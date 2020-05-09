/**
 *@file RawOutput.h
 *@author Bc. Peter Radvan
 *@brief Not formatted output
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "OutputInterface.h"

class RawOutput : public OutputInterface
{
public:
	RawOutput() = default;

	void putBasePolySet(const BasePolySet &s) override;
	void putExtensionFieldPoly(const ExtensionFieldPoly &p) override;
};
