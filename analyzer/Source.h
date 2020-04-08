#pragma once

#include "../polylib/PolyLib.h"

class Source
{
public:
	Source() = default;

	BasePolySet basePolySet() const;
	ExtensionFieldPoly extensionFieldPoly() const;

	void setBasePolySet(const BasePolySet &s);
	void setExtensionFieldPoly(const ExtensionFieldPoly &p);

private:
	BasePolySet m_bps;
	ExtensionFieldPoly m_efp;
};
