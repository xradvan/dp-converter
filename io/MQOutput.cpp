#include "MQOutput.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"

#include <fstream>

MQOutput::MQOutput(const Config &c)
	: m_config(c) {}

void MQOutput::putBasePolySet(const BasePolySet &s)
{
	INFO("Writing BasePolySet in MQ format to file " << m_config.output);
	std::ofstream os{m_config.output};
	if (!os.is_open()) {
		throw MQAException(std::string{"Could not create the output file: "} + m_config.output);
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

void MQOutput::putExtensionFieldPoly(const ExtensionFieldPoly &p)
{
	throw MQAException("Writing ExtensionFieldPoly in MQ format is not supported");
}
