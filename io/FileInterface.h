/**
 *@file FileInterface.h
 *@author Bc. Peter Radvan
 *@brief File interface
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include <string>

class FileInterface
{
public:
	virtual ~FileInterface() = default;
	virtual void setPath(const std::string &path) = 0;
};
