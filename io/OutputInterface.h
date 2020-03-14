/**
 *@file OutputInterface.h
 *@author Bc. Peter Radvan
 *@brief Output interface
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "../polylib/PolyLib.h"

class OutputInterface
{
public:
	virtual ~OutputInterface() = default;

	virtual void putBasePolySet(const BasePolySet &s) = 0;
	virtual void putExtensionFieldPoly(const ExtensionFieldPoly &p) = 0;
};
