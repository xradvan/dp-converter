#include "ToExtendedAlgorithm2.h"
#include "../log/Logger.h"

#include <NTL/vec_GF2E.h>
#include <NTL/mat_GF2E.h>
#include <NTL/ZZ.h>

using namespace NTL;

ExtensionFieldPoly ToExtendedAlgrotihm2::convert(const BasePolySet &toConvert)
{
	int degree = ExtensionField::instance().degree();
	// create vector of partial polynomials
	// which will be used to create mappings
	auto simplePartialPolyVec = createPartialPolyVec();

	// create linear combination of partial polynomials
	// based on the input BasePolySet
	std::vector<ExtensionFieldPoly> complexPartialPolyVec;
	for (int i = 0; i < degree; i++) {
		ExtensionFieldPoly workPoly;
		// quadratic part
		for (int j = 0; j < degree; j++) {
			for (int k = 0; k < degree; k++) {
				if (toConvert.polynomials[i].quadratic[j][k] == 1) {
					ExtensionFieldPoly p;
					ExtensionFieldPoly::mul(p, simplePartialPolyVec[j], simplePartialPolyVec[k]);
					ExtensionFieldPoly::add(workPoly, workPoly, p);
				}
			}
		}
		// linear part
		for (int j = 0; j < degree; j++) {
			if (toConvert.polynomials[i].linear[j] == 1) {
				ExtensionFieldPoly::add(workPoly, workPoly, simplePartialPolyVec[j]);
			}
		}
		// constant part
		workPoly.setCoeff(ZZ{0}, conv<GF2E>(toConvert.polynomials[i].constant));
		complexPartialPolyVec.push_back(workPoly);
	}

	// move complex partial polynomials to the i-th position
	// by multipling alpha to i-th power
	GF2E alpha;
	alpha.LoopHole().SetLength(degree);
	alpha.LoopHole()[1] = 1;
	for (int i = 1; i < degree; i++) {
		GF2E gf2e_w = power(alpha, i);
		// multiply by w
		ZZ toJ = power2_ZZ(degree);
		for (ZZ j{0}; j < toJ; j++) {
			auto gf2e_coeff = complexPartialPolyVec[i].getCoeff(j);
			if (!IsZero(gf2e_coeff)) {
				complexPartialPolyVec[i].setCoeff(j, gf2e_coeff * gf2e_w);
			}
		}
	}

	// sum partial polynomials
	ExtensionFieldPoly result;
	for (int i = 0; i < degree; i++) {
		ExtensionFieldPoly::add(result, result, complexPartialPolyVec[i]);
	}
	return result;
}

std::vector<ExtensionFieldPoly> ToExtendedAlgrotihm2::createPartialPolyVec()
{
	int degree = ExtensionField::instance().degree();
	// alpha term - used later
	GF2E alpha;
	alpha.LoopHole().SetLength(degree);
	alpha.LoopHole()[1] = 1;

	// pre-compute powers for alphas in a row
	Vec<ZZ> powers;
	for (int i = 0; i < degree; i++)
		powers.append(power2_ZZ(i));

	// righ sides to compute simple partial polynomials
	vec_vec_GF2 rightSides;

	// create matrix A (degree x degree)
	mat_GF2E mat_gf2e_A;
	mat_gf2e_A.SetDims(degree, degree);
	for (int i = 0; i < degree; i++) {
		GF2E rowAplha = power(alpha, i);
		// compute right sides in the meantime
		vec_GF2 u = Helpers::gf2eToVec(rowAplha);
		rightSides.append(u);
		// continue in creating matrix
		for (int j = 0; j < degree; j++) {
			mat_gf2e_A[i][j] = power(rowAplha, conv<ZZ>(powers[j]));
		}
	}

	std::vector<ExtensionFieldPoly> result;
	GF2E gf2e_determinant;
	transposeRS(rightSides);

	// compute each partial polynomial
	for (int i = 0; i < degree; i++) {
		vec_GF2E vec_gf2e_x;
		vec_GF2E vec_GF2E_b = getCol(rightSides, i);
		solve(gf2e_determinant, mat_gf2e_A, vec_gf2e_x, vec_GF2E_b); // A*x=b

		GF2E gf2e_null;
		if (gf2e_determinant == gf2e_null) {
			ERROR("gf2e_determinant == gf2e_null");
			return {};
		}

		// create partial polynomial
		ExtensionFieldPoly p;
		for (int j = 0; j < degree; j++) {
			p.setCoeff(powers[j], vec_gf2e_x[j]);
		}

		// append to result list
		result.push_back(p);
	}

	return result;
}

void ToExtendedAlgrotihm2::transposeRS(NTL::vec_vec_GF2 &rightSides)
{
	int degree = ExtensionField::instance().degree();
	auto rs_tmp(rightSides);

	for (int i = 0; i < degree; i++) {
		for (int j = 0; j < degree; j++) {
			rightSides[i][j] = rs_tmp[j][i];
		}
	}
}

vec_GF2E ToExtendedAlgrotihm2::getCol(const NTL::vec_vec_GF2 &rightSides_t, int index)
{
	int degree = ExtensionField::instance().degree();
	vec_GF2E result;

	for (int i = 0; i < degree; i++) {
		vec_GF2 u;
		u.SetLength(degree);
		u[0] = rightSides_t[index][i];
		GF2X gf2x_u = conv<GF2X>(u);
		GF2E gf2e_u;
		gf2e_u.LoopHole() = gf2x_u;
		result.append(gf2e_u);
	}
	return result;
}
