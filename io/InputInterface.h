/**
 *@file InputInterface.h
 *@author Bc. Peter Radvan
 *@brief Input interface
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "../polylib/PolyLib.h"

class InputInterface
{
public:
	virtual ~InputInterface() = default;

	virtual BasePolySet getBasePolySet() = 0;
	virtual ExtensionFieldPoly getExtensionFieldPoly() = 0;
};
