/**
 *@file AppManager.h
 *@author Bc. Peter Radvan
 *@brief AppManager class creates Converter or Analyzer based on the config file
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "Config.h"

class AppManager
{
public:
	AppManager() = default;

	void run(int argc, char *argv[]);
	int exitCode() const;

private:
	Config parseArgs(int argc, char *argv[]);
	void runInternal(const Config &config);

private:
	int m_exitCode;
};
