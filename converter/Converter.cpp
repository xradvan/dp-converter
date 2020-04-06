#include "Converter.h"
#include "ToBaseAlgorithm1.h"
#include "ToExtendedAlgorithm1.h"
#include "../polylib/PolyLib.h"
#include "../log/Logger.h"

Converter::Converter()
	: m_toBaseAlgorithm(new ToBaseAlgorithm1())
	, m_toExtendedAlgorithm(new ToExtendedAlgrotihm1) {}

void Converter::setInput(std::shared_ptr<InputInterface> input)
{
	if (input) {
		m_input = input;
	}
}

void Converter::setOutput(std::shared_ptr<OutputInterface> output)
{
	if (output) {
		m_output = output;
	}
}

void Converter::setToBaseAlgorithm(std::shared_ptr<ToBaseAlgInterface> algorithm)
{
	if (algorithm) {
		m_toBaseAlgorithm = algorithm;
	}
}

void Converter::setToExtendedAlgorithm(std::shared_ptr<ToExtendedAlgInterface> algorithm)
{
	if (algorithm) {
		m_toExtendedAlgorithm = algorithm;
	}
}


void Converter::toBasePolySet()
{
	ExtensionFieldPoly toConvert = m_input->getExtensionFieldPoly();
	INFO("Conversion to base field polynomial started");
	BasePolySet result = m_toBaseAlgorithm->convert(toConvert);
	INFO("Conversion finnished");
	m_output->putBasePolySet(result);
}

void Converter::toExtensionFieldPoly()
{
	BasePolySet toConvert = m_input->getBasePolySet();
	INFO("Conversion to extension field polynomial started");
	ExtensionFieldPoly result = m_toExtendedAlgorithm->convert(toConvert);
	INFO("Conversion finnished");
	m_output->putExtensionFieldPoly(result);
}
