/**
 *@file BasicUI.h
 *@author Bc. Peter Radvan
 *@brief Basic UI for displaying analysis results
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "UIInterface.h"
#include "../app/Config.h"

class BasicUI : public UIInterface
{
public:
	BasicUI(const Config &c);

	void init() override;
	void display(const UIData &data) override;

private:
	Config m_config;
};
