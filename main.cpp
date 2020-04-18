/**
 *@file main.cpp
 *@author Bc. Peter Radvan
 *@brief MQ Analyzer entry point
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#include "app/AppManager.h"
#include "log/Logger.h"
#include "Tests.h"

#include <unistd.h>

// Uncomment to debug
// #define DEBUG

int main(int argc, char *argv[])
{
#ifdef DEBUG
	Tests::test0();
#else
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
		// Conversion algorithm
		config.toExtensionAlg = C_CONVERT_TO_EXT_ALG1;

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

	// Run
	AppManager manager;
	manager.run(config);
	return manager.exitCode();
#endif
}
