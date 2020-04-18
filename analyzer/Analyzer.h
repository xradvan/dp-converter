/**
 *@file Analyzer.h
 *@author Bc. Peter Radvan
 *@brief Main analyzer class
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "Result.h"
#include "ResultProcessorInterface.h"
#include "Source.h"
#include "../app/Config.h"
#include "../ui/UIInterface.h"

#include <memory>
#include <string>
#include <vector>

class Analyzer
{
public:
	Analyzer(const Config &c);

	void setSources(const Sources &s);
	void setResultProcessor(std::shared_ptr<ResultProcessorInterface> p);
	void setUI(std::shared_ptr<UIInterface> ui);

	void run();
	void processResults();

private:
	void addCase(const std::string &fileName, const std::string &caseName, const Source &source);

private:
	Config m_config;

	Sources m_sources;
	FutureResults m_results;

	std::shared_ptr<ResultProcessorInterface> m_resultProcessor;
	std::shared_ptr<UIInterface> m_ui;
};
