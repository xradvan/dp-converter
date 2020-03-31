/**
 *@file ComparableOuput.h
 *@author Bc. Peter Radvan
 *@brief Compare output with source
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "InputInterface.h"
#include "OutputInterface.h"

#include <memory>

class ComparableOutput : public OutputInterface
{
public:
	void putBasePolySet(const BasePolySet &s) override;
	void putExtensionFieldPoly(const ExtensionFieldPoly &p) override;

	void setSource(std::shared_ptr<InputInterface> input);

	bool matchBasePolySet();
	bool matchExtensionFieldPoly();

private:
	BasePolySet m_toCompareBPS;
	ExtensionFieldPoly m_toCompareEFP;
	std::shared_ptr<InputInterface> m_input;
};
