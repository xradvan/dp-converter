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

// Uncomment to debug
// #define DEBUG

int main(int argc, const char *argv[])
{
#ifdef DEBUG
	Tests::test0();
#else
	if (argc == 1) {
		ERROR("Wrong input arguments");
		return EXIT_FAILURE;
	}

	AppManager manager;
	manager.run(argv[1]);
	return manager.exitCode();
#endif
}
