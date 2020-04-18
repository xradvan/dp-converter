/**
 *@file MQFileInput.h
 *@author Bc. Peter Radvan
 *@brief MQ input class
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "FileInputInterface.h"

class MQFileInput : public FileInputInterface
{
public:
	void setPath(const std::string &path) override;

	BasePolySet getBasePolySet() override;
	ExtensionFieldPoly getExtensionFieldPoly() override;

private:
	std::string m_path;
};
