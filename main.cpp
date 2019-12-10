#include <NTL/GF2.h>
#include <NTL/GF2X.h>
#include <NTL/GF2E.h>
#include <NTL/GF2EX.h>
#include <NTL/vec_GF2.h>

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



	GF2EX gf2ex_p = GF2EX(INIT_MONO, 3, gf2e_a);
	cout << gf2ex_p << endl; 
	
	long gf2ex_p_deg = deg(gf2ex_p);
	cout << gf2ex_p_deg << endl;

	// GF2E gf2e_template;
	// cout << gf2e_template << endl;
	// for (int i = 0; i < degree; i++)
	// 	gf2e_template++;
	// cout << gf2e_template << endl;
	
	GF2E gf2e_tmp;
	for (int i = 0; i <= gf2ex_p_deg; i++) {
		gf2e_tmp = coeff(gf2ex_p, i);

		if (!IsZero(gf2e_tmp)) {
			cout << gf2e_tmp << endl;
		}
	}
}