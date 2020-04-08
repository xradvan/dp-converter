#include "Analyzer.h"
#include "Cases.h"
#include "../log/Logger.h"

#include <cmath>
#include <NTL/mat_GF2E.h>

Result Cases::EF_QuadFormRank(const Config &c, const Source &s)
{
	INFO("Starting case: EF_QuadFormRank");
	auto toProcess = s.extensionFieldPoly();
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
	
	SINGLE_VAL_T result;
	result = gauss(mat_GF2E_A);
	return {"EF_QuadFormRank", result};
}

Result Cases::BF_QuadTermRank(const Config &c, const Source &s)
{
	INFO("Starting case: BF_QuadTermRank");
	auto toProcess = s.basePolySet();
	int degree = ExtensionField::instance().degree();

	MULTI_VAL_T result;
	for (int i = 0; i < degree; i++) {
		result.push_back(gauss(toProcess.polynomials[i].quadratic));
	}
	return {"BF_QuadTermRank", result};
}
