#pragma once

#include "ToBaseAlgInterface.h"

class ToBaseAlgorithm1 : public ToBaseAlgInterface
{
	BasePolySet convert(const ExtensionFieldPoly &toConvert) override;
};
