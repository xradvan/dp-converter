#pragma once

#include "InputInterface.h"

class MockInput : public InputInterface
{
	BasePolySet getBasePolySet() override;
	ExtensionFieldPoly getExtensionFieldPoly() override;
};
