#pragma once

#include "OutputInterface.h"

class MQOutput : public OutputInterface
{
public:
	void putBasePolySet(const BasePolySet &s) override;
	void putExtensionFieldPoly(const ExtensionFieldPoly &p) override;
};
