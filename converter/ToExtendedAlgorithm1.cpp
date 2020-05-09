#include "ToExtendedAlgorithm1.h"
#include "../log/Logger.h"

#include <NTL/mat_GF2E.h>

#include <algorithm>
#include <vector>

using namespace NTL;

ExtensionFieldPoly ToExtendedAlgrotihm1::convert(const BasePolySet &toConvert)
{
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
	static Vec<ZZ> powers;
	for (long i = 0; i < degree; i++)
		powers.append(power2_ZZ(i));

	for (long i = 0; i < degree; i++)
		for (long j = i+1; j < degree; j++)
			powers.append(power2_ZZ(i) + power2_ZZ(j));

	powers.append(ZZ(0));

	static mat_GF2E mat_gf2e_A;
	mat_gf2e_A.SetDims(numTerms, numTerms);

	for (int i = 0; i < numTerms; i++)
		for (int j = 0; j < numTerms; j++) {
			power(mat_gf2e_A[i][j], vec_gf2e_inputs2[i], powers[j]);
		}

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
		// SetCoeff(gf2ex_p, powers[i], vec_gf2e_x[i]);
		result.setCoeff(powers[i], vec_gf2e_x[i]);

	return result;
}
