#pragma once

#include "OutputInterface.h"

class RawOutput : public OutputInterface
{
public:
	void putBasePolySet(const BasePolySet &s) override;
	void putExtensionFieldPoly(const ExtensionFieldPoly &p) override;
};
