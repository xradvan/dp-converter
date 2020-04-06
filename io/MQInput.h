/**
 *@file MQInput.h
 *@author Bc. Peter Radvan
 *@brief MQ input class
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "InputInterface.h"
#include "../app/Config.h"

class MQInput : public InputInterface
{
public:
	MQInput(const Config &c);

	BasePolySet getBasePolySet() override;
	ExtensionFieldPoly getExtensionFieldPoly() override;

private:
	Config m_config;
};
