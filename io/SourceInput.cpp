#include "SourceInput.h"

SourceInput::SourceInput(const Source &s)
{
	m_source = s;
}

BasePolySet SourceInput::getBasePolySet()
{
	return m_source.basePolySet;
}

ExtensionFieldPoly SourceInput::getExtensionFieldPoly()
{
	return m_source.extensionFieldPoly;
}
