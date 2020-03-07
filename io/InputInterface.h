#pragma once

#include "../polylib/PolyLib.h"

class InputInterface
{
public:
	virtual ~InputInterface() = default;

	virtual BasePolySet getBasePolySet() = 0;
	virtual ExtensionFieldPoly getExtensionFieldPoly() = 0;
};
