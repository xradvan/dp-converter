/**
 *@file UIInterface.h
 *@author Bc. Peter Radvan
 *@brief UI Interface for displaying analysis results
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "UIData.h"

class UIInterface
{
public:
	virtual ~UIInterface() = default;

	virtual void init() = 0;
	virtual void display(const UIData &data) = 0;
};
