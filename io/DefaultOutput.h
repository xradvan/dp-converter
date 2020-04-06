/**
 *@file DefaultOutput.h
 *@author Bc. Peter Radvan
 *@brief Default output class
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "OutputInterface.h"
#include "../app/Config.h"

class DefaultOutput : public OutputInterface
{
public:
	DefaultOutput(const Config &c);

	void putBasePolySet(const BasePolySet &s) override;
	void putExtensionFieldPoly(const ExtensionFieldPoly &p) override;

private:
	Config m_config;
};
