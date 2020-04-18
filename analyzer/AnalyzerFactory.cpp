#include "AnalyzerFactory.h"
#include "BasicResultProcessor.h"
#include "SourceLoader.h"
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

	// Set Sources
	analyzer->setSources(SourceLoader::loadSources(c));
	// Set Result processor
	analyzer->setResultProcessor(std::make_shared<BasicResultProcessor>());
	// Set UI
	analyzer->setUI(std::make_shared<BasicUI>(c));

	return analyzer;
}
