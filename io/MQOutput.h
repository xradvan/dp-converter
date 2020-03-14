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

class MQOutput : public OutputInterface
{
public:
	void putBasePolySet(const BasePolySet &s) override;
	void putExtensionFieldPoly(const ExtensionFieldPoly &p) override;
};
