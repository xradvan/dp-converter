/**
 *@file ToExtendedAlgInterface.h
 *@author Bc. Peter Radvan
 *@brief Interface for conversion to extension field
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "../polylib/PolyLib.h"

class ToExtendedAlgInterface
{
public:
	virtual ~ToExtendedAlgInterface() = default;

	virtual ExtensionFieldPoly convert(const BasePolySet &toConvert) = 0;
};
