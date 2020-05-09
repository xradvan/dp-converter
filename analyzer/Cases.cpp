#include "Analyzer.h"
#include "Cases.h"
#include "../converter/Converter.h"
#include "../io/SourceInput.h"
#include "../io/SourceOutput.h"
#include "../log/Logger.h"

#include <NTL/ZZ.h>
#include <algorithm>

Result Cases::EF_rank(const Config &c, const Source &s)
{
	INFO("Analyzing case: EF_rank");
	CasesHelpers::reinitNTL();
	auto toProcess = std::get<ExtensionFieldPoly>(s.value);
	return {s.name, CasesHelpers::process(toProcess)};
}

Result Cases::EF_BF_multi(const Config &c, const Source &s)
{
	INFO("Analyzing case: EF_BF_multi");
	CasesHelpers::reinitNTL();
	auto toProcess = std::get<ExtensionFieldPoly>(s.value);

	Converter converter;
	auto output = std::make_shared<SourceOutput>();
	converter.setInput(std::make_shared<SourceInput>(s));
	converter.setOutput(output);
	converter.toBasePolySet();
	auto converted = std::get<BasePolySet>(output->value().value);
	return {s.name, CasesHelpers::process(converted)};
}

Result Cases::BF_multi(const Config &c, const Source &s)
{
	INFO("Analyzing case: BF_multi");
	CasesHelpers::reinitNTL();
	auto toProcess = std::get<BasePolySet>(s.value);
	return {s.name, CasesHelpers::process(toProcess)};
}

Result Cases::BF_EF_rank(const Config &c, const Source &s)
{
	INFO("Analyzing case: BF_EF_rank");
	CasesHelpers::reinitNTL();
	auto toProcess = std::get<BasePolySet>(s.value);

	Converter converter;
	auto output = std::make_shared<SourceOutput>();
	converter.setInput(std::make_shared<SourceInput>(s));
	converter.setOutput(output);
	converter.toExtensionFieldPoly();
	auto converted = std::get<ExtensionFieldPoly>(output->value().value);
	return {s.name, CasesHelpers::process(converted)};
}

NTL::mat_GF2E CasesHelpers::extensionFieldPolyToMatrix(const ExtensionFieldPoly &p)
{
	static NTL::mat_GF2E mat_GF2E_A;
	int degree = ExtensionField::instance().degree();
	mat_GF2E_A.SetDims(degree, degree);

	// compute all possible powers of the terms
	static NTL::Vec<NTL::ZZ> powers;
	for (long i = 0; i < degree; i++)
		powers.append(NTL::power2_ZZ(i));

	for (long i = 0; i < degree; i++)
		for (long j = i+1; j < degree; j++)
			powers.append(NTL::power2_ZZ(i) + NTL::power2_ZZ(j));

	powers.append(NTL::ZZ(0));

	// Fill the matrix in the specific order
	// so after computing (X X^2 X^4 x^8 ...)(matrix)(X X^2 X^4 x^8 ...)^T
	// we get the polynomial back
	long k = 0;
	for (long i = 0; i < degree; i++) {
		for (long j = 0; j < i+1; j++) {
			mat_GF2E_A[j][i] = p.getCoeff(powers[i]);
			k++;
		}
	}
	return mat_GF2E_A;
}

void CasesHelpers::reinitNTL()
{
	auto p = ExtensionField::instance().polynomial().rep;
	NTL::GF2E::init(p);
}

int CasesHelpers::process(const ExtensionFieldPoly &p)
{
	auto toProcess = CasesHelpers::extensionFieldPolyToMatrix(p);
	auto toProcessT = NTL::transpose(toProcess);
	auto sum = toProcess + toProcessT;
	return NTL::gauss(sum);
}

std::vector<int> CasesHelpers::process(const BasePolySet &s)
{
	int degree = ExtensionField::instance().degree();
	auto toProcess(s);
	std::vector<int> result;
	for (int i = 0; i < degree; i++) {
		auto M = toProcess.polynomials[i].quadratic;
		auto M_T = NTL::transpose(M);
		auto sum = M + M_T;
		result.push_back(NTL::gauss(sum));
	}
	return result;
}
