#include "ObserverInput.h"

BasePolySet ObserverInput::getBasePolySet()
{
	return m_basePolySetInternal;
}

ExtensionFieldPoly ObserverInput::getExtensionFieldPoly()
{
	return m_extensionFieldPolyInternal;
}

void ObserverInput::updateBasePolySetInternal(const BasePolySet &s)
{
	m_basePolySetInternal = s;
}

void ObserverInput::updateExtensionFieldPolyInternal(const ExtensionFieldPoly &p)
{
	m_extensionFieldPolyInternal = p;
}
