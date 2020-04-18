/**
 *@file ResultProcessorInterface.h
 *@author Bc. Peter Radvan
 *@brief Interface for Result processors
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "Result.h"
#include "../ui/UIData.h"

#include <string>

class ResultProcessorInterface
{
public:
	virtual ~ResultProcessorInterface() = default;

	virtual UIData process(const std::string &caseName, const ResultVector &results) = 0;
};
