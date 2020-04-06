/**
 *@file AnalyzerFactory.h
 *@author Bc. Peter Radvan
 *@brief Factory for creating an Analyzer instance
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "Analyzer.h"
#include "../app/Config.h"

#include <memory>

struct AnalyzerFactory
{
	static std::unique_ptr<Analyzer> create(const Config &c);
};
