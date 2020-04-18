#include "AppManager.h"
#include "../analyzer/AnalyzerFactory.h"
#include "../converter/ConverterFactory.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"
#include "../polylib/PolyLib.h"

void AppManager::run(const Config &config)
{
	try {
		// Initialize PolyLib
		ExtensionField::instance().init(config.degree);

		// Create converter
		if (config.task == C_TASK_CONVERT) {

			auto converter = ConverterFactory::create(config);
			if (config.coversionType == C_CONVERT_TO_BASE)
				converter->toBasePolySet();
			else if (config.coversionType == C_CONVERT_TO_EXT)
				converter->toExtensionFieldPoly();

		// Create analyzer
		} else if (config.task == C_TASK_ANALYZE) {
			auto analyzer = AnalyzerFactory::create(config);
			analyzer->run();
			analyzer->processResults();
		}

		INFO("Program ended successufully");
		m_exitCode = EXIT_SUCCESS;
	}
	catch(const MQAException &e) {
		ERROR(e.what());
		m_exitCode = EXIT_FAILURE;
	}
	catch (const std::exception &e) {
		ERROR("std error: " << e.what());
		m_exitCode = EXIT_FAILURE;
	}
}

int AppManager::exitCode() const
{
	return m_exitCode;
}
