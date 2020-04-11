#include "BasicUI.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"

#include <algorithm>
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

	os << "==============================\n";
	os << "MQ Analyzer result\n";
	os << "==============================\n\n";

	os << "Name: " << m_config.name << std::endl;
	os << "Description: " << m_config.description << std::endl;
	os << "Date: " << SimpleDateTime::now() << std::endl;
	os << "Extension field degree: " << m_config.degree << std::endl << std::endl;
}

void BasicUI::display(const Result &r)
{
	INFO("Writing result to " << m_config.output);
	std::ofstream os{m_config.output, std::ofstream::app};
	if (!os.is_open()) {
		throw MQAException(std::string{"Could not append results to the output file: "} + m_config.output);
	}

	os << "==============================\n";
	os << "File: " << "" << std::endl;
	os << "Type: " << "" << std::endl;
	os << "Format: " << "" << std::endl;
	os << "Count: " << "" << std::endl;
	os << "==============================\n";

}
