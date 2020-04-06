/**
 *@file MQAException.h
 *@author Bc. Peter Radvan
 *@brief Class for reprezenting exceptions in MQ Analyzer
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include <string>

class MQAException
{
public:
	MQAException(const std::string &what)
		: m_what(what) {}

	std::string what() const { return m_what; }

private:
	std::string m_what;
};