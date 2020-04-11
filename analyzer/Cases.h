/**
 *@file Cases.h
 *@author Bc. Peter Radvan
 *@brief Analyzer Cases definitions
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "Result.h"
#include "Source.h"
#include "../app/Config.h"

struct Cases
{
	static Result EF_rank(const Config &c, const Source &s);
	static Result EF_BF_multi(const Config &c, const Source &s);
	static Result BF_multi(const Config &c, const Source &s);
	static Result BF_EF_rank(const Config &c, const Source &s);
};
