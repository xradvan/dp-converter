#include "RawOutput.h"
#include <iostream>

void RawOutput::putBasePolySet(const BasePolySet &s)
{
	for (auto &p : s.polynomials) {
		std::cout << p << std::endl;
	}
}

void RawOutput::putExtensionFieldPoly(const ExtensionFieldPoly &p)
{
	p.put(std::cout);
}
