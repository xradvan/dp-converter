/**
 *@file Cases.h
 *@author Bc. Peter Radvan
 *@brief Analyzer Cases definitions
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "Result.h"
#include "../app/Config.h"

struct CasesFunc
{
	static Result EF_QuadFormRank(const Config &c);
	static Result BF_QuadTermRank(const Config &c);
};
