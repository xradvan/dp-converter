/**
 *@file Config.h
 *@author Bc. Peter Radvan
 *@brief Struct to hold configuration details
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include <string>

struct Config
{
	std::string name;
	std::string description;
	int degree;
	std::string inputFormat;
	std::string inputPolyType;
	std::string input;
	std::string output;
	std::string task;
	std::string outputFormat;
	std::string convertType;
	std::string cases;

	void load(const std::string &file);
};

// Defines with possible values for config parameters
// Format
#define C_FORMAT_DEFAULT "default"
#define C_FORMAT_MQ "MQ"

// Polynomial type
#define C_POLY_TYPE_BFP "BFP"
#define C_POLY_TYPE_EFP "EFP"

// Task
#define C_TASK_CONVERT "convert"
#define C_TASK_ANALYZE "analyze"

// Convert type
#define C_CONVERT_TO_BASE "to-base"
#define C_CONVERT_TO_EXT "to-extension"

// Analysis cases
#define C_CASES_EF_QuadFormRank	"EF_QuadFormRank"
#define C_CASES_BF_QuadTermRank	"BF_QuadTermRank"