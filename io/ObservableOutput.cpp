#include "ObservableOutput.h"
#include "../log/Logger.h"
#include <algorithm>
#include <mutex>

void ObservableOutput::putBasePolySet(const BasePolySet &s)
{
	std::mutex mutex;
	std::lock_guard<std::mutex> lock(mutex);
	for (auto observer : m_observers) {
		observer->updateBasePolySetInternal(s);
	}
}

void ObservableOutput::putExtensionFieldPoly(const ExtensionFieldPoly &p)
{
	std::mutex mutex;
	std::lock_guard<std::mutex> lock(mutex);
	for (auto observer : m_observers) {
		observer->updateExtensionFieldPolyInternal(p);
	}
}

void ObservableOutput::subscribe(ObserverInput *observer)
{
	if (observer) {
		m_observers.push_back(observer);
	}
}

void ObservableOutput::unsubscribe(ObserverInput *observer)
{
	if (observer) {
		m_observers.erase(
			remove(m_observers.begin(), m_observers.end(), observer),
			m_observers.end()
		);
	}
}
