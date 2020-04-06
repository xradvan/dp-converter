/**
 *@file ConverterFactory.h
 *@author Bc. Peter Radvan
 *@brief Factory for creating a Converter instance
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "Converter.h"
#include "../app/Config.h"

#include <memory>

struct ConverterFactory
{
	static std::unique_ptr<Converter> create(const Config &c);
};
