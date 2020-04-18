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

void Analyzer::setResultProcessor(std::shared_ptr<ResultProcessorInterface> p)
{
	if (p) {
		m_resultProcessor = p;
	}
}

void Analyzer::setUI(std::shared_ptr<UIInterface> ui)
{
	if (ui) {
		m_ui = ui;
	}
}

void Analyzer::run()
{
	INFO("Starting analysis");
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
	for (auto &resultEntry : m_results) {
		auto file = resultEntry.first;
		auto count = std::to_string(m_sources[file].size());
		UIData fileInfo{
			{"", Header1{std::string{"Group: "} + file}},
		};
		m_ui->display(fileInfo);

		for (auto &caseEntry : m_results[file]) {
			ResultVector toProcess;
			std::for_each(caseEntry.second.begin(), caseEntry.second.end(),
				[this, &toProcess](std::future<Result> &r) {
					toProcess.push_back(r.get());
			});
			auto caseName = caseEntry.first;
			auto processed = m_resultProcessor->process(caseName, toProcess);
			m_ui->display(processed);
		}
	}
	INFO("Processing results finnished");
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
