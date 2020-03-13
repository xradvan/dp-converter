#pragma once

#include "OutputInterface.h"
#include "ObserverInput.h"

#include <vector>

class ObservableOutput : public OutputInterface
{
public:
	void putBasePolySet(const BasePolySet &s) override;
	void putExtensionFieldPoly(const ExtensionFieldPoly &p) override;

	void subscribe(ObserverInput *observer);
	void unsubscribe(ObserverInput *observer);

private:
	std::vector<ObserverInput *> m_observers;
};
