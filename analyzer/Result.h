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

#include <future>
#include <map>
#include <string>
#include <variant>
#include <vector>

struct Result
{
	std::string file;
	std::variant<int, std::vector<int>> value;
};

// File -> Case -> Results
using ResultVector = std::vector<Result>;
using FutureResultVector = std::vector<std::future<Result>>;
using FutureResults = std::map<std::string, std::map<std::string, FutureResultVector>>;
