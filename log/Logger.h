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

#define PRINT(x) std::cout << x << std::endl

#define INFO(x) std::cout <<  "INFO  " << x << std::endl
#define INFO_POLY(x) Logger::instance().log(x)
#define ERROR(x) std::cout << "ERROR " << x << std::endl
