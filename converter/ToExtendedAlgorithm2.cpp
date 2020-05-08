#include "ToExtendedAlgorithm2.h"
#include "../log/Logger.h"

#include <NTL/vec_GF2E.h>
#include <NTL/mat_GF2E.h>
#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>

using namespace NTL;

ExtensionFieldPoly ToExtendedAlgrotihm2::convert(const BasePolySet &toConvert)
{
	int degree = ExtensionField::instance().degree();
	// create vector of partial polynomials
	// which will be used to create mappings
	vec_GF2EX simplePartialPolyVec = createPartialPolyVec();

	// create linear combination of partial polynomials
	// based on the input BasePolySet
	vec_GF2EX complexPartialPolyVec;
	for (int i = 0; i < degree; i++) {
		GF2EX workPoly;
		// quadratic part
		for (int j = 0; j < degree; j++) {
			for (int k = 0; k < degree; k++) {
				if (toConvert.polynomials[i].quadratic[j][k] == 1) {
					workPoly += simplePartialPolyVec[j]*simplePartialPolyVec[k];
				}
			}
		}
		// linear part
		for (int j = 0; j < degree; j++) {
			if (toConvert.polynomials[i].linear[j] == 1) {
				workPoly += simplePartialPolyVec[j];
			}
		}
		// constant part
		workPoly += toConvert.polynomials[i].constant;
		complexPartialPolyVec.append(workPoly);
	}

	// move complex partial polynomials to the i-th position
	// by multipling alpha to i-th power
	GF2E alpha;
	alpha.LoopHole().SetLength(degree);
	alpha.LoopHole()[1] = 1;
	GF2E gf2e_null;
	for (int i = 1; i < degree; i++) {
		GF2E gf2e_w = power(alpha, i);
		// multiply by w
		long toJ = power_long(2, degree);
		for (long j = 0; j < toJ; j++) {
			GF2E gf2e_coeff;
			GetCoeff(gf2e_coeff, complexPartialPolyVec[i], j);
			if (gf2e_coeff != gf2e_null) {
				SetCoeff(complexPartialPolyVec[i], j, gf2e_coeff * gf2e_w);
			}
		}
	}

	// sum partial polynomials
	GF2EX gf2ex_sum;
	for (int i = 0; i < degree; i++) {
		gf2ex_sum += complexPartialPolyVec[i];
	}

	ExtensionFieldPoly result;
	result.rep = gf2ex_sum;
	return result;
}

vec_GF2EX ToExtendedAlgrotihm2::createPartialPolyVec()
{
	int degree = ExtensionField::instance().degree();
	// alpha term - used later
	GF2E alpha;
	alpha.LoopHole().SetLength(degree);
	alpha.LoopHole()[1] = 1;

	// pre-compute powers for alphas in a row
	ZZ_p::init(power2_ZZ(degree)-1);
	Vec<ZZ_p> powers;
	for (int i = 0; i < degree; i++)
		powers.append(power(ZZ_p{2}, ZZ{i}));

	// righ sides to compute simple partial polynomials
	vec_vec_GF2 rightSides;

	// create matrix A (degree x degree)
	mat_GF2E mat_gf2e_A;
	mat_gf2e_A.SetDims(degree, degree);
	for (int i = 0; i < degree; i++) {
		GF2E rowAplha = power(alpha, i);
		// compute right sides in the meantime
		vec_GF2 u = Helpers::gf2eToVec(rowAplha);
		rightSides.append(u);
		// continue in creating matrix
		for (int j = 0; j < degree; j++) {
			mat_gf2e_A[i][j] = power(rowAplha, conv<ZZ>(powers[j]));
		}
	}

	vec_GF2EX result;
	GF2E gf2e_determinant;
	transposeRS(rightSides);

	// compute each partial polynomial
	for (int i = 0; i < degree; i++) {
		vec_GF2E vec_gf2e_x;
		vec_GF2E vec_GF2E_b = getCol(rightSides, i);
		solve(gf2e_determinant, mat_gf2e_A, vec_gf2e_x, vec_GF2E_b); // A*x=b

		GF2E gf2e_null;
		if (gf2e_determinant == gf2e_null) {
			ERROR("gf2e_determinant == gf2e_null");
			return {};
		}

		// create partial polynomial
		GF2EX gf2ex_p;
		for (int j = 0; j < degree; j++) {
			SetCoeff(gf2ex_p, conv<long>(powers[j]), vec_gf2e_x[j]);
		}

		// append to result list
		result.append(gf2ex_p);
	}

	return result;
}

void ToExtendedAlgrotihm2::transposeRS(NTL::vec_vec_GF2 &rightSides)
{
	int degree = ExtensionField::instance().degree();
	auto rs_tmp(rightSides);

	for (int i = 0; i < degree; i++) {
		for (int j = 0; j < degree; j++) {
			rightSides[i][j] = rs_tmp[j][i];
		}
	}
}

vec_GF2E ToExtendedAlgrotihm2::getCol(const NTL::vec_vec_GF2 &rightSides_t, int index)
{
	int degree = ExtensionField::instance().degree();
	vec_GF2E result;

	for (int i = 0; i < degree; i++) {
		vec_GF2 u;
		u.SetLength(degree);
		u[0] = rightSides_t[index][i];
		GF2X gf2x_u = conv<GF2X>(u);
		GF2E gf2e_u;
		gf2e_u.LoopHole() = gf2x_u;
		result.append(gf2e_u);
	}
	return result;
}
