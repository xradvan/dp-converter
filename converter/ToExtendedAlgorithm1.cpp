#include "ToExtendedAlgorithm1.h"
#include "../log/Logger.h"

#include <NTL/mat_GF2E.h>

#include <algorithm>
#include <vector>

using namespace NTL;

ExtensionFieldPoly ToExtendedAlgrotihm1::convert(const BasePolySet &toConvert)
{
	INFO("Conversion to extension field polynomial started");

	int degree = ExtensionField::instance().degree();
	int numTerms = degree + ((degree * (degree - 1)) / 2) + 1;

	GF2E alpha;
	alpha.LoopHole().SetLength(degree);
	alpha.LoopHole()[1] = 1;

	vec_GF2E vec_gf2e_inputs2;
	vec_GF2E vec_gf2e_outputs2;

	for (int i = 0; i < numTerms; i++) {
		// map u->v: u = alpha^i
		vec_GF2 u = Helpers::gf2eToVec(power(alpha, i));
		vec_GF2 v = Helpers::eval(toConvert, u);

		GF2X gf2x_u = conv<GF2X>(u);
		GF2E gf2e_u;
		gf2e_u.LoopHole() = gf2x_u;
		vec_gf2e_inputs2.append(gf2e_u);

		GF2X gf2x_v = conv<GF2X>(v);
		GF2E gf2e_v;
		gf2e_v.LoopHole() = gf2x_v;
		vec_gf2e_outputs2.append(gf2e_v);
	}

	// compute all possible powers of the terms
	std::vector<int> powers;
	for (int i = 0; i < degree; i++)
		powers.push_back(pow(2,i));

	for (int i = 0; i < degree; i++)
		for (int j = i+1; j < degree; j++)
			powers.push_back(pow(2,i) + pow(2, j));

	sort(powers.begin(), powers.end());
	auto last = unique(powers.begin(), powers.end());
	powers.erase(last, powers.end());
	powers.push_back(0);

	mat_GF2E mat_gf2e_A;
	mat_gf2e_A.SetDims(numTerms, numTerms);

	for (int i = 0; i < numTerms; i++)
		for (int j = 0; j < numTerms; j++)
			mat_gf2e_A[i][j] = power(vec_gf2e_inputs2[i], powers[j]);

	GF2E gf2e_determinant;
	vec_GF2E vec_gf2e_x;
	vec_GF2E vec_GF2E_b = vec_gf2e_outputs2;
	solve(gf2e_determinant, mat_gf2e_A, vec_gf2e_x, vec_GF2E_b); // A*x=b

	GF2E gf2e_null;
	if (gf2e_determinant == gf2e_null) {
		ERROR("gf2e_determinant == gf2e_null");
		return {};
	}

	ExtensionFieldPoly result;
	GF2X gf2x_tmp_const;
	for (int i = 0; i < degree; i++)
		SetCoeff(gf2x_tmp_const, i, toConvert.polynomials[i].constant);

	GF2EX gf2ex_p; SetCoeff(gf2ex_p, 0, conv<GF2E>(gf2x_tmp_const));
	for (int i = 0; i < numTerms; i++)
		SetCoeff(gf2ex_p, powers[i], vec_gf2e_x[i]);
	result.rep = gf2ex_p;

	return result;
}
