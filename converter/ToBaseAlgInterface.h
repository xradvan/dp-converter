/**
 * @file ToBaseAlgInterface.h
 * @author Bc. Peter Radvan
 * @brief Interface for conversion to base field
 * @version 0.1
 *
 * @copyright Copyright (c) 2020
 *
 */
#pragma once

#include "../polylib/PolyLib.h"

class ToBaseAlgInterface
{
public:
	virtual ~ToBaseAlgInterface() = default;

	virtual BasePolySet convert(const ExtensionFieldPoly &toConvert) = 0;
};
