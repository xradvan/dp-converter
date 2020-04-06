#include "DefaultInput.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"

#include <fstream>

DefaultInput::DefaultInput(const Config &c)
	: m_config(c) {}

BasePolySet DefaultInput::getBasePolySet()
{
	INFO("Reading BasePolySet in default format from file " << m_config.input);
	std::ifstream is{m_config.input};
	if (!is.is_open()) {
		throw MQAException(std::string{"Could not open the file: "} + m_config.input);
	}

	int degree = ExtensionField::instance().degree();
	BasePolySet result;
	for (int i = 0; i < degree; i++) {
		is >> result.polynomials[i].quadratic;
		is >> result.polynomials[i].linear;
		is >> result.polynomials[i].constant;
	}
	return result;
}

ExtensionFieldPoly DefaultInput::getExtensionFieldPoly()
{
	INFO("Reading ExtensionFieldPoly in default format from file " << m_config.input);
	std::ifstream is{m_config.input};
	if (!is.is_open()) {
		throw MQAException(std::string{"Could not open the file: "} + m_config.input);
	}
	ExtensionFieldPoly result;
	is >> result.rep;
	return result;
}
