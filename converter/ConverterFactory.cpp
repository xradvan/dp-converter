#include "ConverterFactory.h"
#include "../err/MQAException.h"
#include "../io/DefaultInput.h"
#include "../io/MQInput.h"
#include "../io/DefaultOutput.h"
#include "../io/MQOutput.h"

std::unique_ptr<Converter> ConverterFactory::create(const Config &c)
{
	auto converter = std::make_unique<Converter>();

	// Set Input
	// if (c.inputFormat == C_FORMAT_DEFAULT)
	// 	converter->setInput(std::make_shared<DefaultInput>(c));
	// else if (c.inputFormat == C_FORMAT_MQ)
	// 	converter->setInput(std::make_shared<MQInput>(c));
	// else
	// 	throw MQAException(std::string{"Unknown converter input format: "} + c.inputFormat);

	// // Set output
	// if (c.outputFormat == C_FORMAT_DEFAULT)
	// 	converter->setOutput(std::make_shared<DefaultOutput>(c));
	// else if (c.outputFormat == C_FORMAT_MQ)
	// 	converter->setOutput(std::make_shared<MQOutput>(c));
	// else
	// 	throw MQAException(std::string{"Unknown converter output format: "} + c.outputFormat);

	// // Set algorithm

	return converter;
}