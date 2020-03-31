#include "ComparableOutput.h"
#include <mutex>

void ComparableOutput::putBasePolySet(const BasePolySet &s)
{
	std::mutex mutex;
	std::lock_guard<std::mutex> lock(mutex);
	m_toCompareBPS = s;

}

void ComparableOutput::putExtensionFieldPoly(const ExtensionFieldPoly &p)
{
	std::mutex mutex;
	std::lock_guard<std::mutex> lock(mutex);
	m_toCompareEFP = p;
}

void ComparableOutput::setSource(std::shared_ptr<InputInterface> input)
{
	if (input) {
		m_input = input;
	}
}

bool ComparableOutput::matchBasePolySet()
{
	return m_toCompareBPS == m_input->getBasePolySet();
}

bool ComparableOutput::matchExtensionFieldPoly()
{
	return m_toCompareEFP == m_input->getExtensionFieldPoly();
}
