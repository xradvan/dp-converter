/**
 *@file DefaultInput.h
 *@author Bc. Peter Radvan
 *@brief Default input class
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "InputInterface.h"
#include "../app/Config.h"

class DefaultInput : public InputInterface
{
public:
	DefaultInput(const Config &c);

	BasePolySet getBasePolySet() override;
	ExtensionFieldPoly getExtensionFieldPoly() override;

private:
	Config m_config;
};
