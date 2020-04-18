#include "DefaultOutput.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"

#include <fstream>

void DefaultOutput::setPath(const std::string &path)
{
	m_path = path;
}

void DefaultOutput::putBasePolySet(const BasePolySet &s)
{
	INFO("Writing BasePolySet in default format to file " << m_path);
	std::ofstream os{m_path};
	if (!os.is_open()) {
		throw MQAException(std::string{"Could not create the output file: "} + m_path);
	}
	int degree = ExtensionField::instance().degree();
	for (int i = 0; i < degree; i++) {
		os << s.polynomials[i].quadratic << std::endl;
		os << s.polynomials[i].linear << std::endl;
		os << s.polynomials[i].constant << std::endl;
	}
}

void DefaultOutput::putExtensionFieldPoly(const ExtensionFieldPoly &p)
{
	INFO("Writing ExtensionFieldPoly in default format to file " << m_path);
	std::ofstream os{m_path};
	if (!os.is_open()) {
		throw MQAException(std::string{"Could not create the output file: "} + m_path);
	}
	os << p.rep;
}
