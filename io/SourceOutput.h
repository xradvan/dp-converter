/**
 *@file SourceOutput.h
 *@author Bc. Peter Radvan
 *@brief Returns Analyzers source class
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "OutputInterface.h"
#include "../analyzer/Source.h"

class SourceOutput : public OutputInterface
{
public:
	void putBasePolySet(const BasePolySet &s);
	void putExtensionFieldPoly(const ExtensionFieldPoly &p);

	Source value();

private:
	Source m_source;
};
