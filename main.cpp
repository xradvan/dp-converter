#include <NTL/GF2.h>
#include <NTL/GF2X.h>
#include <NTL/GF2E.h>
#include <NTL/GF2EX.h>
#include <NTL/mat_GF2.h>
#include <NTL/vector.h>
#include <NTL/vec_GF2.h>
#include <NTL/vec_GF2E.h>

using namespace std;
using namespace NTL;

const long degree = 3;

int main(int argc, char *argv[]) {
	GF2 gf2_a = GF2(0);
	GF2 gf2_b = GF2(1);
	cout << "GF(2) ma prvky: " << gf2_a << " a " << gf2_b << endl << endl;


	GF2X gf2x_p = GF2X(INIT_MONO, degree, 1);
	SetCoeff(gf2x_p, 0); 
	SetCoeff(gf2x_p, 1);
	cout << "Polynom typu GF(2)[X] je napriklad: " << gf2x_p << " = 1 + x + x^3" << endl << endl;


	GF2E::init(gf2x_p);
	cout << "GF(2^3) = GF(2)[X]/(1 + x + x^3) = {0, 1, a, ..., 1 + a + a^2}" << endl;

	GF2E gf2e_a = random_GF2E();
	GF2E gf2e_b = random_GF2E();
	cout << "Napriklad a = " << gf2e_a << ", b = " << gf2e_b << endl;
	cout << "a + b = " << gf2e_a + gf2e_b << endl;
	cout << "a * b = " << gf2e_a * gf2e_b << endl << endl;


	cout << "GF(2^3)[X] = {X^0 x {0, 1, a, ..., 1 + a + a^2}, X^1 x {0, 1, a, ..., 1 + a + a^2}, ... }" << endl;
	GF2EX gf2ex_a = random_GF2EX(3);
	GF2EX gf2ex_b = random_GF2EX(3);
	cout << "Napriklad a = " << gf2ex_a << ", b = " << gf2ex_b << endl;
	cout << "a + b = " << gf2ex_a + gf2ex_b << endl;
	cout << "a * b = " << gf2ex_a * gf2ex_b << endl;



	cout << endl << "***************************************************************************" << endl << endl;



	GF2EX gf2ex_p = GF2EX(INIT_MONO, 3);
	// SetCoeff(gf2ex_p, 2, gf2e_b);
	// cout << gf2ex_p << endl;
	long gf2ex_p_deg = deg(gf2ex_p);


	Vec<mat_GF2> rovnice; 
	rovnice.SetLength(degree);

	mat_GF2 mat_GF2_a0;
	mat_GF2 mat_GF2_a1;
	mat_GF2 mat_GF2_a2;

	mat_GF2_a0.SetDims(degree, degree);
	mat_GF2_a1.SetDims(degree, degree);
	mat_GF2_a2.SetDims(degree, degree);
	
	rovnice[0] = mat_GF2_a0;
	rovnice[1] = mat_GF2_a1;
	rovnice[2] = mat_GF2_a2;

	int a;
	for (int i = 1; i <= gf2ex_p_deg; i++) {
		GF2E gf2e_tmp = coeff(gf2ex_p, i);
		
		if (!IsZero(gf2e_tmp)) {
			// cout << gf2e_tmp << endl;
			
			vec_GF2E vec_GF2E_tmp1;
			vec_GF2E vec_GF2E_tmp2;

			for (int j = 0; j < degree; j++) {
				GF2E gf2e_temp;
				gf2e_temp.LoopHole().SetLength(j + 1);
				gf2e_temp.LoopHole()[j] = 1;

				vec_GF2E_tmp1.append(gf2e_temp);
				vec_GF2E_tmp2.append(gf2e_temp);
			}

			// cout << "vec_GF2E_tmp1: " << vec_GF2E_tmp1 << endl;
			for (int j = 0; j < degree; j++) {
				power(vec_GF2E_tmp1[j], vec_GF2E_tmp1[j], 2);
			}
			cout << "vec_GF2E_tmp1: " << vec_GF2E_tmp1 << endl;
			cout << "vec_GF2E_tmp2: " << vec_GF2E_tmp2 << endl;

			for (int j = 0; j < degree; j++) {
				for (int k = 0; k < degree; k++) {
					GF2E gf2e_temp = vec_GF2E_tmp1[j] * vec_GF2E_tmp2[k]; 
					// cout << "gf2e_temp: " << gf2e_temp << endl;
					long gf2e_temp_deg = deg(gf2e_temp.LoopHole());
					// cout << "gf2e_temp_deg: " << gf2e_temp_deg << endl;

					for (int l = 0; l <= gf2e_temp_deg; l++) {
						if (gf2e_temp.LoopHole()[l] == 1) {
							rovnice[l][j][k] += 1;
						}
					}	
				}
			}
		}
	}

	for (int i = 0; i < degree; i++) {
		for (int j = 0; j < degree; j++) {
			for (int k = 0; k < j; k++ ) {
				rovnice[i][k][j] += rovnice[i][j][k];
				rovnice[i][j][k] = 0;
			}
		}
	}

	cout << "Rovnice: " << rovnice << endl;
}