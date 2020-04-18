/**
 *@file DefaultFileOutput.h
 *@author Bc. Peter Radvan
 *@brief Default output class
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "FileOutputInterface.h"

class DefaultFileOutput : public FileOutputInterface
{
public:
	void setPath(const std::string &path) override;

	void putBasePolySet(const BasePolySet &s) override;
	void putExtensionFieldPoly(const ExtensionFieldPoly &p) override;

private:
	std::string m_path;
};
