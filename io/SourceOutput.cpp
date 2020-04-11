#include "SourceOutput.h"

void SourceOutput::putBasePolySet(const BasePolySet &s)
{
	m_source.basePolySet = s;
}

void SourceOutput::putExtensionFieldPoly(const ExtensionFieldPoly &p)
{
	m_source.extensionFieldPoly = p;
}

Source SourceOutput::value()
{
	return m_source;
}
