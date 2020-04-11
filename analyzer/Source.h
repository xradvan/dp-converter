#pragma once

#include "../polylib/PolyLib.h"

#include <map>
#include <string>
#include <variant>
#include <vector>

struct Source
{
	std::string name;
	std::variant<BasePolySet, ExtensionFieldPoly> value;
};

// File -> Sources
using Sources = std::map<std::string, std::vector<Source>>;
