#include "Source.h"

BasePolySet Source::basePolySet() const
{
	return m_bps;
}

ExtensionFieldPoly Source::extensionFieldPoly() const
{
	return m_efp;
}

void Source::setBasePolySet(const BasePolySet &s)
{
	m_bps = s;
}

void Source::setExtensionFieldPoly(const ExtensionFieldPoly &p)
{
	m_efp = p;
}
