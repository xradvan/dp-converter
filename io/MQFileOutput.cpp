#include "MQFileOutput.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"

#include <fstream>

void MQFileOutput::setPath(const std::string &path)
{
	m_path = path;
}

void MQFileOutput::putBasePolySet(const BasePolySet &s)
{
	INFO("Writing BasePolySet in MQ format to file " << m_path);
	std::ofstream os{m_path};
	if (!os.is_open()) {
		throw MQAException(std::string{"Could not create the output file: "} + m_path);
	}
	int degree = ExtensionField::instance().degree();
	for (int i = 0; i < degree; i++) {
		for (int j = 0; j < degree; j++)
			for (int k = 0; k <= j; k++)
				os << s.polynomials[i].quadratic[k][j] << " ";

		for (int j = 0; j < degree; j++)
			os << s.polynomials[i].linear[j] << " ";

		os << s.polynomials[i].constant << " ;" << std::endl;
	}
}

void MQFileOutput::putExtensionFieldPoly(const ExtensionFieldPoly &p)
{
	throw MQAException("Writing ExtensionFieldPoly in MQ format is not supported");
}
