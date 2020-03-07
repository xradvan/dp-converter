#pragma once

#include "../polylib/PolyLib.h"

class ToBaseAlgInterface
{
public:
	virtual ~ToBaseAlgInterface() = default;

	virtual BasePolySet convert(const ExtensionFieldPoly &toConvert) = 0;
};
