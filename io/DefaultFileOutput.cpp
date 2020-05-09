#include "DefaultFileOutput.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"

#include <fstream>

void DefaultFileOutput::setPath(const std::string &path)
{
	m_path = path;
}

void DefaultFileOutput::putBasePolySet(const BasePolySet &s)
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

void DefaultFileOutput::putExtensionFieldPoly(const ExtensionFieldPoly &p)
{
	INFO("Writing ExtensionFieldPoly in default format to file " << m_path);
	std::ofstream os{m_path};
	if (!os.is_open()) {
		throw MQAException(std::string{"Could not create the output file: "} + m_path);
	}
	p.put(os);
}
