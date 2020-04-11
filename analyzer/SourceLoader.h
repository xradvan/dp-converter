/**
 *@file SourceLoader.h
 *@author Bc. Peter Radvan
 *@brief Loads Sources for analysis
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "Source.h"
#include "../app/Config.h"

struct SourceLoader
{
	static Sources loadSources(const Config &c);
};
