#include "AnalyzerFactory.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"
#include "../io/DefaultInput.h"
#include "../io/MQInput.h"
#include "../ui/BasicUI.h"

#include <iterator>
#include <sstream>
#include <vector>

std::unique_ptr<Analyzer> AnalyzerFactory::create(const Config &c)
{
	INFO("Creating Analyzer");
	auto analyzer = std::make_unique<Analyzer>(c);

	// Input
	std::shared_ptr<InputInterface> input;
	if (c.inputFormat == C_FORMAT_DEFAULT) 
		input = std::make_shared<DefaultInput>(c);
	else if (c.inputFormat == C_FORMAT_MQ)
		input = std::make_shared<MQInput>(c);
	else
		throw MQAException(std::string{"Unknown input format: "} + c.inputFormat);

	// Set source
	Source source;
	if (c.inputPolyType == C_POLY_TYPE_BFP)
		source.setBasePolySet(input->getBasePolySet());
	else if (c.inputPolyType == C_POLY_TYPE_EFP)
		source.setExtensionFieldPoly(input->getExtensionFieldPoly());
	else
		throw MQAException(std::string{"Unknown input polynomial type: "} + c.inputPolyType);
	analyzer->setSource(source);

	// Set UI
	analyzer->setUI(std::make_shared<BasicUI>(c));

	// Parse cases
	std::istringstream iss(c.cases);
	std::vector<std::string> parsedCases(std::istream_iterator<std::string>{iss},
		std::istream_iterator<std::string>());

	for (const auto &pc : parsedCases) {
		analyzer->addCase(pc);
	}
	return analyzer;
}
