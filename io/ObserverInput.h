/**
 *@file ObserverInput.h
 *@author Bc. Peter Radvan
 *@brief Gets data from ObservableOutput.
 *@warning Must be connected via subscribe()
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "InputInterface.h"

class ObserverInput : public InputInterface
{
public:
	BasePolySet getBasePolySet() override;
	ExtensionFieldPoly getExtensionFieldPoly() override;

private:
	friend class ObservableOutput;

	void updateBasePolySetInternal(const BasePolySet &s);
	void updateExtensionFieldPolyInternal(const ExtensionFieldPoly &p);

private:
	BasePolySet m_basePolySetInternal;
	ExtensionFieldPoly m_extensionFieldPolyInternal;
};
