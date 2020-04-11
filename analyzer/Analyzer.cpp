#include "Analyzer.h"
#include "Cases.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"

#include <algorithm>

Analyzer::Analyzer(const Config &c)
	: m_config(c) {}

void Analyzer::setSources(const Sources &s)
{
	m_sources = s;
}

void Analyzer::setUI(std::shared_ptr<UIInterface> ui)
{
	if (ui) {
		m_ui = ui;
	}
}

void Analyzer::run()
{
	INFO("Running analysis");
	for (const auto &file : m_config.files) {
		for (const auto &source : m_sources[file.name]) {
			for (const auto &caseName : file.cases) {
				addCase(file.name, caseName, source);
			}
		}
	}
}

void Analyzer::processResults()
{
	m_ui->init();
	// std::for_each(m_cases.begin(), m_cases.end(), [this](std::future<Result> &c){ this->m_ui->display(c.get()); });
}

void Analyzer::addCase(const std::string &fileName, const std::string &caseName, const Source &source)
{
	if (caseName == C_CASES_EF_Rank)
		m_results[fileName][caseName].push_back(std::async(std::launch::async, Cases::EF_rank, m_config, source));
	else if (caseName == C_CASES_EF_BF_multi)
		m_results[fileName][caseName].push_back(std::async(std::launch::async, Cases::EF_BF_multi, m_config, source));
	else if (caseName == C_CASES_BF_multi)
		m_results[fileName][caseName].push_back(std::async(std::launch::async, Cases::BF_multi, m_config, source));
	else if (caseName == C_CASES_BF_EF_rank)
		m_results[fileName][caseName].push_back(std::async(std::launch::async, Cases::BF_EF_rank, m_config, source));
	else
		throw MQAException(std::string{"Unknown analyzer case: "} + caseName);
}
