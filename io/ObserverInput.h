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
