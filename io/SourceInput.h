/**
 *@file SourceInput.h
 *@author Bc. Peter Radvan
 *@brief Get input from Analyzer Source class
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "InputInterface.h"
#include "../analyzer/Source.h"

class SourceInput : public InputInterface
{
public:
	SourceInput(const Source &s);

	BasePolySet getBasePolySet() override;
	ExtensionFieldPoly getExtensionFieldPoly() override;

private:
	Source m_source;
};
