#include "PolyLib.h"
#include <assert.h>

PrimitivePoly PrimitivePolyFactory::createPolyOfDegree(int n)
{
	// TODO
	assert(n >= 3);
	assert(n <= 4);

	PrimitivePoly result;
	result.rep.SetLength(n+1);
	if (n == 3) {
		NTL::SetCoeff(result.rep, 0, 1);
		NTL::SetCoeff(result.rep, 1, 1);
		NTL::SetCoeff(result.rep, 3, 1);
	}
	else {
		NTL::SetCoeff(result.rep, 0, 1);
		NTL::SetCoeff(result.rep, 1, 1);
		NTL::SetCoeff(result.rep, 4, 1);
	}

	return result;
}
