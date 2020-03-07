#include "RawOutput.h"
#include <iostream>
#include "../log/Logger.h"

void RawOutput::putBasePolySet(const BasePolySet &s)
{
	PRINT("\nBasePolySet:");
	for (auto &p : s.polynomials) {
		std::cout << p << std::endl;
	}
}

void RawOutput::putExtensionFieldPoly(const ExtensionFieldPoly &p)
{
	PRINT("\nExtensionFieldPoly:");
	std::cout << p.rep << std::endl;
}
