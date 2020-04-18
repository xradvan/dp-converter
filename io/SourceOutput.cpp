#include "SourceOutput.h"

void SourceOutput::putBasePolySet(const BasePolySet &s)
{
	m_source.value = s;
}

void SourceOutput::putExtensionFieldPoly(const ExtensionFieldPoly &p)
{
	m_source.value = p;
}

Source SourceOutput::value()
{
	return m_source;
}
