#include "BasicUI.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"

#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string>

BasicUI::BasicUI(const Config &c)
	: m_config(c) {}

void BasicUI::init()
{
	std::ofstream os{m_config.output};
	if (!os.is_open()) {
		throw MQAException(std::string{"Could not create the output file: "} + m_config.output);
	}

	os << "======================================\n";
	os << "          MQ Analyzer result\n";
	os << "======================================\n\n";

	os << "Name: " << m_config.name << std::endl;
	os << "Description: " << m_config.description << std::endl;
	os << "Date: " << SimpleDateTime::now() << std::endl;
	os << "Extension field degree: " << m_config.degree << std::endl << std::endl;
}

void BasicUI::display(const UIData &data)
{
	std::ofstream os{m_config.output, std::ofstream::app};
	if (!os.is_open()) {
		throw MQAException(std::string{"Could not append results to the output file: "} + m_config.output);
	}
	for (auto &val : data) {
		if (std::holds_alternative<Header1>(val.second)) {
			os << "======================================\n";
			os << std::get<Header1>(val.second) << std::endl;
			os << "======================================\n";
		}
		else if (std::holds_alternative<Header2>(val.second)) {
			os << "--------------------------------------\n";
			os << std::get<Header2>(val.second) << std::endl;
			os << "--------------------------------------\n";
		}
		else if (std::holds_alternative<Separator>(val.second)) {
			os << std::endl;
		}
		else if (std::holds_alternative<int>(val.second)) {
			os << val.first << ": " << std::get<int>(val.second) << std::endl;
		}
		else if (std::holds_alternative<float>(val.second)) {
			os << val.first << ": " << std::setprecision(5) << std::get<float>(val.second) << std::endl;
		}
		else if (std::holds_alternative<std::string>(val.second)) {
			os << val.first << ": " << std::get<std::string>(val.second) << std::endl;
		}
		else if (std::holds_alternative<std::vector<int>>(val.second)) {
			auto vec = std::get<std::vector<int>>(val.second);
			os << val.first << ":" << std::endl;
			std::for_each(vec.begin(), vec.end(), [&](int i) { os << i << " "; });
			os << std::endl;
		}
	}
	os << std::endl;
}
