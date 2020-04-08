/**
 *@file Result.h
 *@author Bc. Peter Radvan
 *@brief Result of a single Case in the analysis
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include <string>
#include <variant>
#include <vector>

#define SINGLE_VAL_T int
#define MULTI_VAL_T std::vector<int>

struct Result
{
	std::string name;
	std::variant<SINGLE_VAL_T, MULTI_VAL_T > value;
};
