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

	void run(const Config &config);
	int exitCode() const;

private:
	int m_exitCode;
};
