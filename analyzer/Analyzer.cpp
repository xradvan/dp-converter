#include "Analyzer.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"

#include <algorithm>

Analyzer::Analyzer(const Config &c)
	: m_config(c) {}

void Analyzer::setSource(const Source &s)
{
	m_source = s;
}

void Analyzer::setUI(std::shared_ptr<UIInterface> ui)
{
	if (ui) {
		m_ui = ui;
	}
}

void Analyzer::addCase(const std::string &c)
{
	INFO("Adding case " << c);
	if (c == C_CASES_EF_QuadFormRank)
		m_cases.push_back(std::async(std::launch::async, Cases::EF_QuadFormRank, m_config, m_source));
	else if (c == C_CASES_BF_QuadTermRank)
		m_cases.push_back(std::async(std::launch::async, Cases::BF_QuadTermRank, m_config, m_source));
	else
		throw MQAException(std::string{"Unknown analyzer case: "} + c);
}

void Analyzer::run()
{
	INFO("Running analysis");
	m_ui->init();
	std::for_each(m_cases.begin(), m_cases.end(), [this](std::future<Result> &c){ this->m_ui->display(c.get()); });
}
