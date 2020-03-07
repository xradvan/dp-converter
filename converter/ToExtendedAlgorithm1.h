#pragma once

#include "ToExtendedAlgInterface.h"

class ToExtendedAlgrotihm1 : public ToExtendedAlgInterface
{
public:
	ExtensionFieldPoly convert(const BasePolySet &toConvert) override;
};
