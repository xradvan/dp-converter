/**
 *@file Logger.h
 *@author Bc. Peter Radvan
 *@brief Logger functions
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include <iostream>

#define PRINT(x) std::cout << x << std::endl

#define INFO(x) std::cout <<  "INFO  " << x << std::endl
#define ERROR(x) std::cout << "ERROR " << x << std::endl
