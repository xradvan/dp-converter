#include "converter/Converter.h"
#include "io/MockInput.h"
#include "io/RawOutput.h"
#include "polylib/PolyLib.h"

#include <memory>

int main()
{
	int degree = 4;
	ExtensionField::instance().init(degree);

	auto input = std::make_shared<MockInput>();
	auto output = std::make_shared<RawOutput>();
	
	Converter converter;
	converter.setInput(input);
	converter.setOutput(output);

	converter.toBasePolySet();
}