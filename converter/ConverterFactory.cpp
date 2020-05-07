#include "ConverterFactory.h"
#include "../err/MQAException.h"
#include "../converter/ToExtendedAlgorithm2.h"
#include "../io/FileInputInterface.h"
#include "../io/FileOutputInterface.h"
#include "../io/DefaultFileInput.h"
#include "../io/MQFileInput.h"
#include "../io/DefaultFileOutput.h"
#include "../io/MQFileOutput.h"

std::unique_ptr<Converter> ConverterFactory::create(const Config &c)
{
	auto converter = std::make_unique<Converter>();

	// Set Input
	std::shared_ptr<FileInputInterface> input;
	if (c.inputFile.format == C_FORMAT_DEFAULT)
		input = std::make_shared<DefaultFileInput>();
	else if (c.inputFile.format == C_FORMAT_MQ)
		input = std::make_shared<MQFileInput>();
	else
		throw MQAException(std::string{"Unknown converter input format: "} + c.inputFile.format);
	input->setPath(c.inputFile.name);
	converter->setInput(input);

	// Set Output
	std::shared_ptr<FileOutputInterface> output;
	if (c.outputFile.format == C_FORMAT_DEFAULT)
		output = std::make_shared<DefaultFileOutput>();
	else if (c.outputFile.format == C_FORMAT_MQ)
		output = std::make_shared<MQFileOutput>();
	else
		throw MQAException(std::string{"Unknown converter output format: "} + c.outputFile.format);

	output->setPath(c.outputFile.name);
	converter->setOutput(output);

	// Set algorithm
	if (c.toExtensionAlg == C_CONVERT_TO_EXT_ALG2) {
		converter->setToExtendedAlgorithm(std::make_shared<ToExtendedAlgrotihm2>());
	}
	return converter;
}