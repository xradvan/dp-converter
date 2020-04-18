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
#include <vector>

struct File
{
	std::string name;
	std::string type;
	std::string format;
	std::vector<std::string> cases;
};

struct Config
{
	std::string name;
	std::string description;
	int degree;
	std::string task;
	// Analyzer
	std::string inputBaseDir;
	std::vector<File> files;
	std::string output;
	// Converter
	std::string coversionType;
	File inputFile;
	File outputFile;

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
#define C_CONVERT_TO_BASE "to_base"
#define C_CONVERT_TO_EXT "to_extension"

// Analysis cases
#define C_CASES_EF_Rank		"EF_rank"
#define C_CASES_EF_BF_multi	"EF_BF_multi"
#define C_CASES_BF_multi	"BF_multi"
#define C_CASES_BF_EF_rank	"BF_EF_rank"

// Not set
#define C_NOT_SET "NOT SET"