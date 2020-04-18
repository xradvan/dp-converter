#include "DefaultFileInput.h"
#include "../err/MQAException.h"

#include <fstream>

void DefaultFileInput::setPath(const std::string &path)
{
	m_path = path;
}

BasePolySet DefaultFileInput::getBasePolySet()
{
	std::ifstream is{m_path};
	if (!is.is_open()) {
		throw MQAException(std::string{"Could not open the file: "} + m_path);
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

ExtensionFieldPoly DefaultFileInput::getExtensionFieldPoly()
{
	std::ifstream is{m_path};
	if (!is.is_open()) {
		throw MQAException(std::string{"Could not open the file: "} + m_path);
	}
	ExtensionFieldPoly result;
	is >> result.rep;
	return result;
}
