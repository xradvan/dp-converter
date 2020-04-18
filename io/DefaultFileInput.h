/**
 *@file DefaultFileInput.h
 *@author Bc. Peter Radvan
 *@brief Default input class
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "FileInputInterface.h"

class DefaultFileInput : public FileInputInterface
{
public:
	void setPath(const std::string &path) override;

	BasePolySet getBasePolySet() override;
	ExtensionFieldPoly getExtensionFieldPoly() override;

private:
	std::string m_path;
};
