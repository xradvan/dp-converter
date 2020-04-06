#include "MQInput.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"

#include <fstream>
#include <sstream>

MQInput::MQInput(const Config &c)
	: m_config(c) {}

BasePolySet MQInput::getBasePolySet()
{
	INFO("Reading BasePolySet in MQ format from file " << m_config.input);
	std::ifstream is{m_config.input};
	if (!is.is_open()) {
		throw MQAException(std::string{"Could not open the file: "} + m_config.input);
	}

	BasePolySet result;
	std::string str;
	int degree = ExtensionField::instance().degree();
	for (int i = 0; std::getline(is, str); i++) {
		std::istringstream iss{str};
		for (int j = 0; j < degree; j++)
			for (int k = 0; k <= j; k++)
				iss >> result.polynomials[i].quadratic[k][j];

		for (int j = 0; j < degree; j++)
			iss >> result.polynomials[i].linear[j];

		iss >> result.polynomials[i].constant;
	}
	return result;
}

ExtensionFieldPoly MQInput::getExtensionFieldPoly()
{
	throw MQAException("Reading ExtensionFieldPoly in MQ format is not supported");
}
