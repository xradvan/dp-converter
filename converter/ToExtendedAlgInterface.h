#pragma once

#include "../polylib/PolyLib.h"

class ToExtendedAlgInterface
{
public:
	virtual ~ToExtendedAlgInterface() = default;

	virtual ExtensionFieldPoly convert(const BasePolySet &toConvert) = 0;
};
