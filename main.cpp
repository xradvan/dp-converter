#include <math.h>
#include <NTL/GF2XFactoring.h>
#include <NTL/GF2.h>
#include <NTL/GF2X.h>
#include <NTL/GF2E.h>
#include <NTL/GF2EX.h>
#include <NTL/mat_GF2.h>
#include <NTL/mat_GF2E.h>
#include <NTL/vector.h>
#include <NTL/vec_GF2.h>
#include <NTL/vec_GF2E.h>

using namespace std;
using namespace NTL;

// Degree of extension
const long degree = 4;

#define DEG_SIZE 8
#define DEG_TYPE uint8_t

struct PolyPowers
{
	int p1;
	int p2;
	PolyPowers() : p1(-1), p2(-1) {}
};

struct QuadraticPoly
{
	mat_GF2 mat_gf2_quadratic;
	vec_GF2 vec_gf2_linear;
	GF2 gf2_const;
	int degree;

	QuadraticPoly() {}
	void SetDegree(long d)
	{
		degree = d;
		init(degree);
	}

	void init(int d)
	{
		mat_gf2_quadratic.SetDims(d, d);
		vec_gf2_linear.SetLength(d);
	}

	friend ostream& operator<<(ostream& os, const QuadraticPoly& p)
	{
		os << "[";
		for (int i = 0; i < p.degree; i++) {
			os << p.mat_gf2_quadratic[i];
		}
		os << "] ";

		os << p.vec_gf2_linear << " " << p.gf2_const;
	}
};

vec_GF2 intToVec(DEG_TYPE value)
{
	vec_GF2 v;
	v.SetLength(DEG_SIZE);

	for (int i = 0; i < DEG_SIZE; i++) {
		v[i] = value & 0x1;
		value >>= 1;
	}
	return v;
}

vec_GF2 intToVec(int value, int degree) {
	vec_GF2 v;
	v.SetLength(degree);

	for (int i = 0; i < degree; i++) {
		v[i] = value & 0x1;
		value >>= 1;
	}
	return v;
}

PolyPowers getPowers(DEG_TYPE degree)
{
	PolyPowers powers;
	vec_GF2 v = intToVec(degree);
	long hw = weight(v);
	int *p = &(powers.p1);
	if (hw == 2) {
		for (int i = 0; i < v.length(); i++) {
			if (v[i] == 1) {
				*p = i;
				p = &(powers.p2);
			}
		}
	} else if (hw == 1) {
		for (int i = 0; i < v.length(); i++) {
			if (v[i] == 1) {
				powers.p1 = i;
			}
		}
	}
	return powers;
}

void setAlphas(vec_GF2E &vec_gf2e, long p)
{
	for (int i = 0; i < degree; i++) {
		GF2E gf2e_temp;
		gf2e_temp.LoopHole().SetLength(i + 1);
		gf2e_temp.LoopHole()[i] = 1;

		power(gf2e_temp, gf2e_temp, pow(2, p));
		vec_gf2e.append(gf2e_temp);
	}
}

void rawOutput(const Vec<QuadraticPoly> &equations)
{
	cout << endl;
	cout << "Set: " << endl;
	for (auto &r : equations) {
		cout << r << endl;
	}
}

void MQChallengeOutpu(const Vec<QuadraticPoly> &equations)
{
	cout << "Galois Field : GF(2)" << endl;
	cout << "Number of variables (n) : " << degree << endl;
	cout << "Number of equations (m) : " << degree << endl;
	cout << "Seed : 0" << endl;
	cout << "Order : Graded reverse lexicographic order" << endl;
	cout << "******************************************" << endl;

	for (int i = 0; i < degree; i++) {
		for (int j = 0; j < degree; j++)
			for (int k = 0; k <= j; k++)
				cout << equations[i].mat_gf2_quadratic[k][j] << " ";

		for (int j = 0; j < degree; j++)
			cout << equations[i].vec_gf2_linear[j] << " ";

		cout << equations[i].gf2_const << ";" << endl;
	}

	cout << endl;
}

void test(const Vec<QuadraticPoly> &equations, const GF2EX &gf2ex_p)
{
	cout << endl << "Tests:" << endl;
	int max_value = pow(2, degree);
	for (int i = 0; i < max_value; i++) {
		Vec<QuadraticPoly> equations_tmp(equations);

		vec_GF2 pt = intToVec(i, degree);
		cout << i << ". " << pt << " -> ";
		vec_GF2 ct; ct.SetLength(degree);

		for (int i = 0; i < degree; i++)
			for (int j = 0; j < degree; j++)
				if (pt[j] == 0) {
					equations_tmp[i].vec_gf2_linear[j] = 0;

					for (int k = 0; k < degree; k++) // for (int k = j; k < N; k++)
						equations_tmp[i].mat_gf2_quadratic[j][k] = 0;
					for (int k = 0; k < degree; k++) // for (int k = 0; k < j; k++)
						equations_tmp[i].mat_gf2_quadratic[k][j] = 0;
				}

		for (int i = 0; i < degree; i++) {
			ct[i] += equations_tmp[i].gf2_const;
			for (int j = 0; j < degree; j++) {
				ct[i] += equations_tmp[i].vec_gf2_linear[j];
				for (int k = 0; k < degree; k++)
					ct[i] += equations_tmp[i].mat_gf2_quadratic[j][k];
			}
		}

		cout << ct << " ?= ";

		GF2X gf2x_pt = conv<GF2X>(pt);

		GF2E gf2e_pt;
		gf2e_pt.LoopHole() = gf2x_pt;

		// GF2E gf2e_result = eval(gf2ex_p, gf2e_pt);
		GF2E gf2e_result;
		int gf2ex_p_deg = deg(gf2ex_p);
		for (int i = 0; i <= gf2ex_p_deg; i++) {
			GF2E gf2e_tmp = coeff(gf2ex_p, i);

			if (!IsZero(gf2e_tmp)) {
				gf2e_result += gf2e_tmp * power(gf2e_pt, i);
			}
		}

		vec_GF2 vec_gf2_result = conv<vec_GF2>(conv<GF2X>(gf2e_result));
		vec_gf2_result.SetLength(degree);

		cout << vec_gf2_result << " " << (ct == vec_gf2_result ? "OK" : "NOK") << endl;
	}
}

int main(int argc, char *argv[]) {
	GF2X gf2x_p = BuildSparseIrred_GF2X(degree);
	GF2E::init(gf2x_p);

	// Polynomial to convert
	// GF2EX gf2ex_p = random_GF2EX(7);
	// GF2EX gf2ex_p = GF2EX(INIT_MONO, 3);

	GF2E c5;
	c5.LoopHole().SetLength(4);
	c5.LoopHole()[0] = 1;

	GF2E c4;
	c4.LoopHole().SetLength(4);
	c4.LoopHole()[1] = 1;

	GF2E c3;
	c3.LoopHole().SetLength(4);
	c3.LoopHole()[0] = 1;
	c3.LoopHole()[3] = 1;

	GF2E c2;
	c2.LoopHole().SetLength(4);
	c2.LoopHole()[0] = 1;
	c2.LoopHole()[1] = 1;
	c2.LoopHole()[2] = 1;

	GF2E c1;
	c1.LoopHole().SetLength(4);
	c1.LoopHole()[1] = 1;

	GF2EX gf2ex_p;
	gf2ex_p.SetLength(6);
	SetCoeff(gf2ex_p, 0, c1);
	SetCoeff(gf2ex_p, 2, c2);
	SetCoeff(gf2ex_p, 3, c3);
	SetCoeff(gf2ex_p, 4, c4);
	SetCoeff(gf2ex_p, 5, c5);

	cout << "gf2ex_p: " << endl << gf2ex_p << endl;
	long gf2ex_p_deg = deg(gf2ex_p);

	Vec<QuadraticPoly> equations;
	equations.SetLength(degree);
	for (int i = 0; i < degree; i++) {
		equations[i].SetDegree(degree);
	}

	// constant part
	GF2E gf2e_tmp0 = coeff(gf2ex_p, 0);
	for (int i = 0; i <= deg(gf2e_tmp0.LoopHole()); i++) {
		if (gf2e_tmp0.LoopHole()[i] == 1) {
			equations[i].gf2_const += 1;
		}
	}

	for (int i = 1; i <= gf2ex_p_deg; i++) {
		GF2E gf2e_tmp = coeff(gf2ex_p, i);
		
		if (!IsZero(gf2e_tmp)) {
			// cout << gf2e_tmp << endl;
			PolyPowers p = getPowers(i);

			if (p.p1 == -1 && p.p2 == -1) {
				cout << "Wrong input " << endl;
				return -1;
			}

			vec_GF2E vec_gf2e_tmp1;
			if (p.p1 > -1) {
				setAlphas(vec_gf2e_tmp1, p.p1);
			}

			// multiply by alphas
			mul(vec_gf2e_tmp1, gf2e_tmp, vec_gf2e_tmp1);

			// distinguish between X^(2^i + 2^j) and X^(2^i)
			if (p.p2 > -1) {
				vec_GF2E vec_gf2e_tmp2;
				setAlphas(vec_gf2e_tmp2, p.p2);

				for (int j = 0; j < degree; j++) {
					for (int k = 0; k < degree; k++) {
						GF2E gf2e_temp = vec_gf2e_tmp1[j] * vec_gf2e_tmp2[k];
						long gf2e_temp_deg = deg(gf2e_temp.LoopHole());

						for (int l = 0; l <= gf2e_temp_deg; l++) {
							if (gf2e_temp.LoopHole()[l] == 1) {
								equations[l].mat_gf2_quadratic[j][k] += 1;
							}
						}
					}
				}
			} else {
				for (int j = 0; j < degree; j++) {
					for (int l = 0; l <= deg(vec_gf2e_tmp1[j].LoopHole()); l++) {
						if (vec_gf2e_tmp1[j].LoopHole()[l] == 1) {
							equations[l].vec_gf2_linear[j] += 1;
						}
					}
				}
			}
		}
	}

	// merge same expressions: x1x2 a x2x1
	for (int i = 0; i < degree; i++) {
		for (int j = 0; j < degree; j++) {
			for (int k = 0; k < j; k++ ) {
				equations[i].mat_gf2_quadratic[k][j] += equations[i].mat_gf2_quadratic[j][k];
				equations[i].mat_gf2_quadratic[j][k] = 0;
			}
		}
	}

	// print result
	rawOutput(equations);

	// cout << "Test: " << endl;
	test(equations, gf2ex_p);

	cout << "\nTransformation 1: " << endl;

	int max_value = pow(2, degree);
	vec_GF2E vec_gf2e_inputs1;
	vec_GF2E vec_gf2e_outputs1;

	for (int i = 0; i < max_value; i++) {
		Vec<QuadraticPoly> equations_tmp(equations);

		vec_GF2 pt = intToVec(i, degree);
		vec_GF2 ct; ct.SetLength(degree);

		for (int i = 0; i < degree; i++)
			for (int j = 0; j < degree; j++)
				if (pt[j] == 0) {
					equations_tmp[i].vec_gf2_linear[j] = 0;

					for (int k = 0; k < degree; k++) {
						equations_tmp[i].mat_gf2_quadratic[j][k] = 0;
						equations_tmp[i].mat_gf2_quadratic[k][j] = 0;
					}
				}

		for (int i = 0; i < degree; i++) {
			ct[i] += equations_tmp[i].gf2_const;
			for (int j = 0; j < degree; j++) {
				ct[i] += equations_tmp[i].vec_gf2_linear[j];
				for (int k = 0; k < degree; k++)
					ct[i] += equations_tmp[i].mat_gf2_quadratic[j][k];
			}
		}

		GF2X gf2x_pt = conv<GF2X>(pt);
		GF2E gf2e_pt;
		gf2e_pt.LoopHole() = gf2x_pt;
		vec_gf2e_inputs1.append(gf2e_pt);

		GF2X gf2x_ct = conv<GF2X>(ct);
		GF2E gf2e_ct;
		gf2e_ct.LoopHole() = gf2x_ct;
		vec_gf2e_outputs1.append(gf2e_ct);
	}

	GF2EX gf2ex_px1 = interpolate(vec_gf2e_inputs1, vec_gf2e_outputs1);
	cout << gf2ex_px1 << " " << (gf2ex_p == gf2ex_px1 ? "OK" : "NOK") << endl;


	cout << "Transformation 2:" << endl;
	int num = degree + ((degree * (degree - 1)) / 2);

	vec_GF2E vec_gf2e_inputs2;
	vec_GF2E vec_gf2e_outputs2;

	for (int i = 1; i <= num; i++) {
		Vec<QuadraticPoly> equations_tmp(equations);

		vec_GF2 pt = intToVec(i, degree);
		vec_GF2 ct; ct.SetLength(degree);

		for (int i = 0; i < degree; i++)
			for (int j = 0; j < degree; j++)
				if (pt[j] == 0) {
					equations_tmp[i].vec_gf2_linear[j] = 0;

					for (int k = 0; k < degree; k++) {
						equations_tmp[i].mat_gf2_quadratic[j][k] = 0;
						equations_tmp[i].mat_gf2_quadratic[k][j] = 0;
					}
				}

		for (int i = 0; i < degree; i++) {
			ct[i] += equations_tmp[i].gf2_const;
			for (int j = 0; j < degree; j++) {
				ct[i] += equations_tmp[i].vec_gf2_linear[j];
				for (int k = 0; k < degree; k++)
					ct[i] += equations_tmp[i].mat_gf2_quadratic[j][k];
			}
		}

		GF2X gf2x_pt = conv<GF2X>(pt);
		GF2E gf2e_pt;
		gf2e_pt.LoopHole() = gf2x_pt;
		vec_gf2e_inputs2.append(gf2e_pt);

		GF2X gf2x_ct = conv<GF2X>(ct);
		GF2E gf2e_ct;
		gf2e_ct.LoopHole() = gf2x_ct;
		vec_gf2e_outputs2.append(gf2e_ct);
	}

	int powers[num];
	for (int i = 0; i < degree; i++)
		powers[i] = pow(2, i);

	int tmp = degree;
	for (int i = 0; i < degree; i++)
		for (int j = i + 1; j < degree; j++)
			powers[tmp++] = pow(2, i) + pow(2, j);

	mat_GF2E mat_gf2e_A;
	mat_gf2e_A.SetDims(num, num);

	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			mat_gf2e_A[i][j] = power(vec_gf2e_inputs2[i], powers[j]);

	GF2E gf2e_determinant;
	vec_GF2E vec_gf2e_x;
	vec_GF2E vec_GF2E_b = vec_gf2e_outputs2;
	solve(gf2e_determinant, mat_gf2e_A, vec_gf2e_x, vec_GF2E_b); // A*x=b
	
	GF2E gf2e_null;
	if (gf2e_determinant == gf2e_null) {
		cout << "Failure: gf2e_determinant == gf2e_null" << endl;
	} else {
		GF2X gf2x_tmp_const;
		for (int i = 0; i < degree; i++)
			SetCoeff(gf2x_tmp_const, i, equations[i].gf2_const);

		GF2EX gf2ex_px2; SetCoeff(gf2ex_px2, 0, conv<GF2E>(gf2x_tmp_const));
		for (int i = 0; i < num; i++)
			SetCoeff(gf2ex_px2, powers[i], vec_gf2e_x[i]);
		
		cout << gf2ex_px2 << " " << (gf2ex_p == gf2ex_px2 ? "OK" : "NOK") << endl;
	}
}