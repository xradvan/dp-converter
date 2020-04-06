#include "AnalyzerFactory.h"
#include "../log/Logger.h"
#include "../ui/BasicUI.h"

#include <iterator>
#include <sstream>
#include <vector>

std::unique_ptr<Analyzer> AnalyzerFactory::create(const Config &c)
{
	INFO("Creating Analyzer");
	auto analyzer = std::make_unique<Analyzer>(c);

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
