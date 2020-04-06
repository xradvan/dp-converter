/**
 *@file MQOutput.h
 *@author Bc. Peter Radvan
 *@brief Output in MQ Challenge format
 *@warning Implemented for BasePolySet only!
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "OutputInterface.h"
#include "../app/Config.h"

class MQOutput : public OutputInterface
{
public:
	MQOutput(const Config &c);

	void putBasePolySet(const BasePolySet &s) override;
	void putExtensionFieldPoly(const ExtensionFieldPoly &p) override;

private:
	Config m_config;
};
