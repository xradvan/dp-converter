/**
 *@file MockInput.h
 *@author Bc. Peter Radvan
 *@brief Mock input for testings
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "InputInterface.h"

class MockInput : public InputInterface
{
	BasePolySet getBasePolySet() override;
	ExtensionFieldPoly getExtensionFieldPoly() override;
};
