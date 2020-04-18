#include "SourceInput.h"

SourceInput::SourceInput(const Source &s)
{
	m_source = s;
}

BasePolySet SourceInput::getBasePolySet()
{
	return std::get<BasePolySet>(m_source.value);
}

ExtensionFieldPoly SourceInput::getExtensionFieldPoly()
{
	return std::get<ExtensionFieldPoly>(m_source.value);
}
