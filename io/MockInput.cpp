#include "MockInput.h"

#include <NTL/GF2E.h>
#include <NTL/GF2EX.h>

using namespace NTL;

BasePolySet MockInput::getBasePolySet()
{

}

ExtensionFieldPoly MockInput::getExtensionFieldPoly()
{
	ExtensionFieldPoly result;
	int degree = ExtensionField::instance().degree();
	if (degree == 3) {
		result.rep = GF2EX(INIT_MONO, 3);
	} else {
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
		result.rep = gf2ex_p;
	}
	return result;
}
