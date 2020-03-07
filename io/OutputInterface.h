#pragma once

#include "../polylib/PolyLib.h"

class OutputInterface
{
public:
	virtual ~OutputInterface() = default;

	virtual void putBasePolySet(const BasePolySet &s) = 0;
	virtual void putExtensionFieldPoly(const ExtensionFieldPoly &p) = 0;
};
