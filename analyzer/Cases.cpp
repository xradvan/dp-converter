#include "Analyzer.h"
#include "Cases.h"
#include "../log/Logger.h"

#include <cmath>
#include <NTL/mat_GF2E.h>

Result Cases::EF_rank(const Config &c, const Source &s)
{
	auto toProcess = std::get<ExtensionFieldPoly>(s.value);
	int degree = ExtensionField::instance().degree();

	// Create matrix
	int dim = ceil(sqrt(toProcess.rep.rep.length()));
	auto p = ExtensionField::instance().polynomial().rep;
	NTL::GF2E::init(p);

	NTL::mat_GF2E mat_GF2E_A;
	mat_GF2E_A.SetDims(dim, dim);
	int k = 0;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			mat_GF2E_A[i][j] = toProcess.rep.rep[k++];
		}
	}
	return {s.name, gauss(mat_GF2E_A)};
}

Result Cases::EF_BF_multi(const Config &c, const Source &s)
{
	return {};
}

Result Cases::BF_multi(const Config &c, const Source &s)
{
	auto toProcess = std::get<BasePolySet>(s.value);
	int degree = ExtensionField::instance().degree();

	std::vector<int> result;
	for (int i = 0; i < degree; i++) {
		result.push_back(gauss(toProcess.polynomials[i].quadratic));
	}
	return {s.name, result};
}

Result Cases::BF_EF_rank(const Config &c, const Source &s)
{
	return {};
}
