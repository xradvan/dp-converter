#include "ConverterFactory.h"
#include "../err/MQAException.h"
#include "../io/FileInputInterface.h"
#include "../io/FileOutputInterface.h"
#include "../io/DefaultInput.h"
#include "../io/MQInput.h"
#include "../io/DefaultOutput.h"
#include "../io/MQOutput.h"

std::unique_ptr<Converter> ConverterFactory::create(const Config &c)
{
	auto converter = std::make_unique<Converter>();

	// Set Input
	std::shared_ptr<FileInputInterface> input;
	if (c.inputFile.format == C_FORMAT_DEFAULT)
		input = std::make_shared<DefaultInput>();
	else if (c.inputFile.format == C_FORMAT_MQ)
		input = std::make_shared<MQInput>();
	else
		throw MQAException(std::string{"Unknown converter input format: "} + c.inputFile.format);
	input->setPath(c.inputFile.name);
	converter->setInput(input);

	// Set Output
	std::shared_ptr<FileOutputInterface> output;
	if (c.outputFile.format == C_FORMAT_DEFAULT)
		output = std::make_shared<DefaultOutput>();
	else if (c.outputFile.format == C_FORMAT_MQ)
		output = std::make_shared<MQOutput>();
	else
		throw MQAException(std::string{"Unknown converter output format: "} + c.outputFile.format);

	output->setPath(c.outputFile.name);
	converter->setOutput(output);

	// // Set algorithm
	return converter;
}