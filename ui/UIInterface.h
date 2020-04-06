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

#include "../analyzer/Result.h"

class UIInterface
{
public:
	virtual ~UIInterface() = default;

	virtual void init() = 0;
	virtual void display(const Result &r) = 0;
};
