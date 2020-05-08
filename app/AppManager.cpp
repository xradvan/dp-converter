#include "AppManager.h"
#include "../analyzer/AnalyzerFactory.h"
#include "../converter/ConverterFactory.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"
#include "../polylib/PolyLib.h"

#include <unistd.h>

void AppManager::run(int argc, char *argv[])
{
	try {
		auto config = parseArgs(argc, argv);
		runInternal(config);
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

Config AppManager::parseArgs(int argc, char *argv[])
{
	Config config;
	File infile;
	File outfile;
	bool setDefaults = true;
	int option;
	while((option = getopt(argc, argv, ":c:d:t:i:e:s:o:a:p:x")) != -1) {
		switch(option){
			case 'c':
			{
				config.load(optarg);
				setDefaults = false;
			}
				break;
			case 'd':
				config.degree = std::atoi(optarg);
				break;
			case 't':
				config.task = optarg;
				break;
			case 'i':
				infile.name = optarg;
				break;
			case 'e':
				infile.type = optarg;
				break;
			case 's':
				infile.cases.push_back(optarg);
				break;
			case 'o':
			{
				config.output = optarg;
				outfile.name = optarg;
			}
				break;
			case 'a':
				config.toExtensionAlg = optarg;
				break;
			case 'p':
				config.coversionType = optarg;
				break;
			case ':':
				ERROR("Option needs a value");
				break;
			case '?':
				printf("unknown option: %c\n", optopt);
				break;
		}
	}
	// Set defaults
	if (setDefaults) {
		// IO format
		if (config.coversionType == C_CONVERT_TO_EXT) {
			infile.format = C_FORMAT_MQ;
			outfile.format = C_FORMAT_DEFAULT;
		}
		else {
			infile.format = C_FORMAT_DEFAULT;
			outfile.format = C_FORMAT_MQ;
		}

		config.files.push_back(infile);
		config.inputFile = infile;
		config.outputFile = outfile;
	}
	return config;
}

void AppManager::runInternal(const Config &config)
{
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
