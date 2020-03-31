#include "Tests.h"

#include "converter/Converter.h"
#include "converter/ToExtendedAlgorithm2.h"
#include "io/MockInput.h"
#include "io/ComparableOutput.h"
#include "io/RawOutput.h"
#include "io/ObserverInput.h"
#include "io/ObservableOutput.h"
#include "log/Logger.h"
#include "polylib/PolyLib.h"

#include <memory>

void Tests::test1()
{
	// int degree = ExtensionField::instance().degree();
	// cout << endl << "Tests:" << endl;
	// int max_value = pow(2, degree);
	// for (int i = 0; i < max_value; i++) {
	// 	BasePolySet bpSet;

	// 	vec_GF2 pt = Helpers::intToVec(i);
	// 	cout << i << ". " << pt << " -> ";
	// 	vec_GF2 ct; ct.SetLength(degree);

	// 	for (int i = 0; i < degree; i++)
	// 		for (int j = 0; j < degree; j++)
	// 			if (pt[j] == 0) {
	// 				bpSet.polynomials[i].linear[j] = 0;

	// 				for (int k = 0; k < degree; k++) // for (int k = j; k < N; k++)
	// 					bpSet.polynomials[i].quadratic[j][k] = 0;
	// 				for (int k = 0; k < degree; k++) // for (int k = 0; k < j; k++)
	// 					bpSet.polynomials[i].quadratic[k][j] = 0;
	// 			}

	// 	for (int i = 0; i < degree; i++) {
	// 		ct[i] += bpSet.polynomials[i].constant;
	// 		for (int j = 0; j < degree; j++) {
	// 			ct[i] +=bpSet.polynomials[i].linear[j];

	// 			for (int k = 0; k < degree; k++)
	// 				ct[i] += bpSet.polynomials[i].quadratic[j][k];
	// 		}
	// 	}

	// 	cout << ct << " ?= ";

	// 	GF2X gf2x_pt = conv<GF2X>(pt);

	// 	GF2E gf2e_pt;
	// 	gf2e_pt.LoopHole() = gf2x_pt;

	// 	// GF2E gf2e_result = eval(gf2ex_p, gf2e_pt);
	// 	GF2E gf2e_result;
	// 	int gf2ex_p_deg = deg(testPoly.rep);
	// 	for (int i = 0; i <= gf2ex_p_deg; i++) {
	// 		GF2E gf2e_tmp = coeff(testPoly.rep, i);

	// 		if (!IsZero(gf2e_tmp)) {
	// 			gf2e_result += gf2e_tmp * power(gf2e_pt, i);
	// 		}
	// 	}

	// 	vec_GF2 vec_gf2_result = conv<vec_GF2>(conv<GF2X>(gf2e_result));
	// 	vec_gf2_result.SetLength(degree);

	// 	cout << vec_gf2_result << " " << (ct == vec_gf2_result ? "OK" : "NOK") << endl;
	// }
}

void Tests::test2()
{
	int degree = 3;
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

	PRINT("");
	INFO("Running backward conversion");
	// Conversion 2 - revert
	converter.setInput(input2);
	converter.setOutput(output2);
	converter.toExtensionFieldPoly();
}

void Tests::test3()
{
	int degree = 3;
	ExtensionField::instance().init(degree);
	Converter converter;

	// IO
	auto input = std::make_shared<MockInput>();
	auto output = std::make_shared<ComparableOutput>();
	output->setSource(input);

	converter.setInput(input);
	converter.setOutput(output);
	converter.setToExtendedAlgorithm(std::make_shared<ToExtendedAlgrotihm2>());
	converter.toBasePolySet();
	if (output->matchBasePolySet()) {
		OK("");
	} else {
		FAIL("");
	}
}
