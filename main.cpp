#include <NTL/GF2.h>
#include <NTL/GF2X.h>
#include <NTL/GF2E.h>
#include <NTL/GF2EX.h>
#include <NTL/vec_GF2.h>

using namespace std;
using namespace NTL;

int main(int argc, char *argv[]) {
	GF2X P = GF2X(INIT_MONO, 3, 1);
	SetCoeff(P, 0);
	SetCoeff(P, 1);
	
	cout << "P: " << P << " = 1 + x + x^3" << endl << endl;

	GF2E::init(P);
	
	GF2E a = random_GF2E();
	cout << "a: " << a << endl;
	
	GF2E b = random_GF2E();
	cout << "b: " << b << endl;
	
	cout << "a + b: " << a + b << endl;
	cout << "a * b: " << a * b << endl;

	GF2EX x = random_GF2EX(3);
	cout << x << endl;

	GF2EX y = random_GF2EX(3);
	cout << y << endl;

	cout << x * y << endl;
}