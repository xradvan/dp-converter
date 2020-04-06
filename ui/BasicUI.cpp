#include "BasicUI.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"

#include <fstream>
#include <string>

BasicUI::BasicUI(const Config &c)
	: m_config(c) {}

void BasicUI::init()
{
	INFO("Creating output file: " << m_config.output);
	std::ofstream os{m_config.output};
	if (!os.is_open()) {
		throw MQAException(std::string{"Could not create the output file: "} + m_config.output);
	}

	os << "MQ Analyzer result\n\n";
	os << "Name: " << m_config.name << "\n";
	os << "Description: " << m_config.description << "\n";
	os << "Date: " << SimpleDateTime::now() << "\n\n";

	os << "Extension field degree: " << m_config.degree << "\n";
	os << "Input format: " << m_config.inputFormat << "\n";
	os << "Input file: " << m_config.input << "\n\n";
}

void BasicUI::display(const Result &r)
{
	INFO("Writing result to " << m_config.output);
	std::ofstream os{m_config.output, std::ofstream::app};
	if (!os.is_open()) {
		throw MQAException(std::string{"Could not append results to the output file: "} + m_config.output);
	}
	os << "Case  : " << r.name << "\n";
	os << "Result: " << r.value << "\n\n";
}
