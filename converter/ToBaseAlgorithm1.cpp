#include "ToBaseAlgorithm1.h"
#include "../err/MQAException.h"

#include <NTL/GF2E.h>
#include <NTL/vec_GF2E.h>

#include "assert.h"

using namespace NTL;

BasePolySet ToBaseAlgorithm1::convert(const ExtensionFieldPoly &toConvert)
{
	int degree = ExtensionField::instance().degree();
	BasePolySet result;

	// Start by computing constant part
	GF2E constant = coeff(toConvert.rep, 0);
	int constantDeg = deg(constant.LoopHole());

	for (int i = 0; i <= constantDeg; i++) {
		if (constant.LoopHole()[i] == 1) {
			result.polynomials[i].constant += 1;
		}
	}

	// Convert terms
	int toConvertDeg = deg(toConvert.rep);
	for (int i = 1; i <= toConvertDeg; i++) {
		GF2E term = coeff(toConvert.rep, i);

		if (!IsZero(term)) {
			PolyPowers p = PolyPowers::getPowers(i);
			if (p.p1 == PolyPowers::NOT_SET && p.p2 == PolyPowers::NOT_SET) {
				throw MQAException("Term could not be processed converted");
			}

			vec_GF2E vec_gf2e_tmp1;
			if (p.p1 > PolyPowers::NOT_SET) {
				Helpers::setAlphas(vec_gf2e_tmp1, p.p1);
			}

			// Multiply by alphas
			mul(vec_gf2e_tmp1, term, vec_gf2e_tmp1);

			// Distinguish between X^(2^i + 2^j) and X^(2^i)
			if (p.p2 > PolyPowers::NOT_SET) {
				vec_GF2E vec_gf2e_tmp2;
				Helpers::setAlphas(vec_gf2e_tmp2, p.p2);

				for (int j = 0; j < degree; j++) {
					for (int k = 0; k < degree; k++) {
						GF2E gf2e_temp = vec_gf2e_tmp1[j] * vec_gf2e_tmp2[k];
						long gf2e_temp_deg = deg(gf2e_temp.LoopHole());

						for (int l = 0; l <= gf2e_temp_deg; l++) {
							if (gf2e_temp.LoopHole()[l] == 1) {
								result.polynomials[l].quadratic[j][k] += 1;
							}
						}
					}
				}
			} else {
				for (int j = 0; j < degree; j++) {
					for (int l = 0; l <= deg(vec_gf2e_tmp1[j].LoopHole()); l++) {
						if (vec_gf2e_tmp1[j].LoopHole()[l] == 1) {
							result.polynomials[l].linear[j] += 1;
						}
					}
				}
			}
		}
	}

	// Merge same expressions: x1x2 a x2x1
	for (int i = 0; i < degree; i++) {
		for (int j = 0; j < degree; j++) {
			for (int k = 0; k < j; k++ ) {
				result.polynomials[i].quadratic[k][j] += result.polynomials[i].quadratic[j][k];
				result.polynomials[i].quadratic[j][k] = 0;
			}
		}
	}
	return result;
}
