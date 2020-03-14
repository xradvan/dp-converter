#include "converter/Converter.h"
#include "io/MockInput.h"
#include "io/RawOutput.h"
#include "io/ObserverInput.h"
#include "io/ObservableOutput.h"
#include "polylib/PolyLib.h"

#include <memory>

int main()
{
	int degree = 5;
	ExtensionField::instance().init(degree);
	Converter converter;

	// IO
	auto input1 = std::make_shared<MockInput>();
	auto output1 = std::make_shared<ObservableOutput>();

	auto input2 = std::make_shared<ObserverInput>();
	output1->subscribe(input2.get());
	auto output2 = std::make_shared<RawOutput>();

	// Conversion 1
	converter.setInput(input1);
	converter.setOutput(output1);
	converter.toBasePolySet();

	// Conversion 2 - revert
	converter.setInput(input2);
	converter.setOutput(output2);
	converter.toExtensionFieldPoly();
}
