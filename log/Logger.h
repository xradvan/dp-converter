/**
 *@file Logger.h
 *@author Bc. Peter Radvan
 *@brief Logger functions
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "../io/OutputInterface.h"
#include "../polylib/PolyLib.h"

#include <iostream>
#include <memory>
#include <string>

struct SimpleDateTime
{
	static std::string now();
};

class Logger
{
public:
	static Logger &instance();
	void setOutput(std::shared_ptr<OutputInterface> output);

	void log(const BasePolySet &s);
	void log(const ExtensionFieldPoly &p);

public:
	Logger(Logger const&) = delete;
	void operator=(Logger const&) = delete;

private:
	Logger();

private:
	std::shared_ptr<OutputInterface> m_output;

};

const std::string RedColor("\033[0;31m");
const std::string GreenColor("\033[1;32m");

#define PRINT(x) std::cout << x << std::endl

#define INFO(x)
#define INFO_POLY(x)
#define ERROR(x) std::cout << SimpleDateTime::now() << " ERROR " << x << std::endl

#define OK(x) std::cout << GreenColor << "OK " << x << std::endl
#define FAIL(x) std::cout << GreenColor << "FAIL " << x << std::endl
