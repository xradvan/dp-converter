#include "MockInput.h"

#include <NTL/GF2E.h>
#include <NTL/GF2EX.h>

using namespace NTL;

BasePolySet MockInput::getBasePolySet()
{
	BasePolySet result;
	int degree = ExtensionField::instance().degree();
	if (degree == 3) {
		result.polynomials[0].quadratic[0][0] = 1;
		result.polynomials[0].quadratic[1][1] = 1;
		result.polynomials[0].quadratic[1][2] = 1;
		result.polynomials[0].quadratic[2][2] = 1;

		result.polynomials[1].quadratic[0][1] = 1;
		result.polynomials[1].quadratic[0][2] = 1;
		result.polynomials[1].quadratic[1][1] = 1;

		result.polynomials[2].quadratic[0][1] = 1;
		result.polynomials[2].quadratic[2][2] = 1;
	}
	return result;
}

ExtensionFieldPoly MockInput::getExtensionFieldPoly()
{
	ExtensionFieldPoly result;
	int degree = ExtensionField::instance().degree();
	if (degree == 3) {
		result.setCoeff(ZZ{3}, 1);
	}
	// switch (degree)
	// {
	// case 2:
	// 	result.rep = GF2EX(INIT_MONO, 2);
	// 	break;
	// case 3:
	// 	result.rep = GF2EX(INIT_MONO, 3);
	// 	break;
	// case 4:
	// {
	// 	GF2E c5;
	// 	c5.LoopHole().SetLength(4);
	// 	c5.LoopHole()[0] = 1;

	// 	GF2E c4;
	// 	c4.LoopHole().SetLength(4);
	// 	c4.LoopHole()[1] = 1;

	// 	GF2E c3;
	// 	c3.LoopHole().SetLength(4);
	// 	c3.LoopHole()[0] = 1;
	// 	c3.LoopHole()[3] = 1;

	// 	GF2E c2;
	// 	c2.LoopHole().SetLength(4);
	// 	c2.LoopHole()[0] = 1;
	// 	c2.LoopHole()[1] = 1;
	// 	c2.LoopHole()[2] = 1;

	// 	GF2E c1;
	// 	c1.LoopHole().SetLength(4);
	// 	c1.LoopHole()[1] = 1;

	// 	GF2EX gf2ex_p;
	// 	gf2ex_p.SetLength(6);
	// 	SetCoeff(gf2ex_p, 0, c1);
	// 	SetCoeff(gf2ex_p, 2, c2);
	// 	SetCoeff(gf2ex_p, 3, c3);
	// 	SetCoeff(gf2ex_p, 4, c4);
	// 	SetCoeff(gf2ex_p, 5, c5);
	// 	result.rep = gf2ex_p;
	// }
	// 	break;

	// case 5:
	// 	result.rep = GF2EX(INIT_MONO, 5);
	// 	break;
	// default:
	// 	break;
	// }
	return result;
}
