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
#include "../polylib/PolyLib.h"

#include <NTL/mat_GF2E.h>

struct Cases
{
	static Result EF_rank(const Config &c, const Source &s);
	static Result EF_BF_multi(const Config &c, const Source &s);
	static Result BF_multi(const Config &c, const Source &s);
	static Result BF_EF_rank(const Config &c, const Source &s);
};

struct CasesHelpers
{
	static void reinitNTL();
	static NTL::mat_GF2E extensionFieldPolyToMatrix(const ExtensionFieldPoly &p);
	static int process(const ExtensionFieldPoly &p);
	static std::vector<int> process(const BasePolySet &s);
};
