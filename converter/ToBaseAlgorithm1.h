/**
 *@file ToBaseAlgorithm1.h
 *@author Bc. Peter Radvan
 *@brief Default to base field conversion algorithm
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "ToBaseAlgInterface.h"

class ToBaseAlgorithm1 : public ToBaseAlgInterface
{
	BasePolySet convert(const ExtensionFieldPoly &toConvert) override;
};
