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

int main(int argc, char *argv[])
{
#ifdef DEBUG
	Tests::test0();
#else
	// Run
	AppManager manager;
	manager.run(argc, argv);
	return manager.exitCode();
#endif
}
