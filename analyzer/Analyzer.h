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

#include "Cases.h"
#include "Result.h"
#include "Source.h"
#include "../app/Config.h"
#include "../ui/UIInterface.h"

#include <future>
#include <memory>
#include <string>
#include <vector>

class Analyzer
{
public:
	Analyzer(const Config &c);

	void setSource(const Source &s);
	void setUI(std::shared_ptr<UIInterface> ui);

	void addCase(const std::string &c);
	void run();

private:
	Config m_config;
	Source m_source;
	std::vector<std::future<Result> > m_cases;
	std::shared_ptr<UIInterface> m_ui;
};
