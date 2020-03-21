/**
 *@file ToExtendedAlgorithm1.h
 *@author Bc. Peter Radvan
 *@brief The first algorithm to convert base polynomial to extension field representation
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "ToExtendedAlgInterface.h"

class ToExtendedAlgrotihm1 : public ToExtendedAlgInterface
{
public:
	ExtensionFieldPoly convert(const BasePolySet &toConvert) override;
};
