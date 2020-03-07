#pragma once

#include "../io/InputInterface.h"
#include "../io/OutputInterface.h"
#include "ToBaseAlgInterface.h"
#include "ToExtendedAlgInterface.h"

#include <memory>

class Converter
{
public:
	Converter();

	void setInput(std::shared_ptr<InputInterface> input);
	void setOutput(std::shared_ptr<OutputInterface> output);

	void setToBaseAlgorithm(std::shared_ptr<ToBaseAlgInterface> algorithm);
	void setToExtendedAlgorithm(std::shared_ptr<ToExtendedAlgInterface> algorithm);

	void toBasePolySet();
	void toExtensionFieldPoly();

private:
	std::shared_ptr<InputInterface> m_input;
	std::shared_ptr<OutputInterface> m_output;

	std::shared_ptr<ToBaseAlgInterface> m_toBaseAlgorithm;
	std::shared_ptr<ToExtendedAlgInterface> m_toExtendedAlgorithm;
};
