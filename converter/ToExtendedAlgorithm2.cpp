#include "ToExtendedAlgorithm2.h"
#include "../log/Logger.h"

#include <NTL/vec_GF2E.h>
#include <NTL/mat_GF2E.h>

using namespace NTL;

ExtensionFieldPoly ToExtendedAlgrotihm2::convert(const BasePolySet &toConvert)
{
	int degree = ExtensionField::instance().degree();

	GF2E alpha;
	alpha.LoopHole().SetLength(degree);
	alpha.LoopHole()[1] = 1;

	// pre-compute powers for alphas in a row
	std::vector<int> powers;
	for (int i = 0; i < degree; i++)
		powers.push_back(pow(2,i));

	// righ sides to compute partial polynomials
	vec_vec_GF2 rightSides;

	// create matrix A (degree x degree)
	mat_GF2E mat_gf2e_A;
	mat_gf2e_A.SetDims(degree, degree);
	for (int i = 0; i < degree; i++) {
		GF2E rowAplha = power(alpha, i);
		// eval: compute right sides in the meantime
		vec_GF2 u = Helpers::gf2eToVec(rowAplha);
		vec_GF2 v = Helpers::eval(toConvert, u);
		rightSides.append(v);
		// continue in creating matrix
		for (int j = 0; j < degree; j++) {
			mat_gf2e_A[i][j] = power(rowAplha, powers[j]);
		}
	}

	vec_GF2EX partialPolynomials = createPartialPolyVec(mat_gf2e_A, powers, rightSides);

	// for (int i = 1; i < degree; i++) {
	// 	GF2E gf2e_w = power(alpha, i);
	// 	PRINT("w " << gf2e_w);
	// 	// multiply by w
	// 	for (int j = 0; j < 5; j++) {
	// 		GF2E gf2e_coeff;
	// 		GetCoeff(gf2e_coeff, partialPolynomials[i], j);
	// 		SetCoeff(partialPolynomials[i], j, gf2e_coeff * gf2e_w);
	// 	}
	// }
	
	// GF2EX gf2ex_sum;
	// for (int i = 0; i < degree; i++) {
	// 	gf2ex_sum += partialPolynomials[i];
	// 	// PRINT(partialPolynomials[i]);
	// }

	// PRINT(gf2ex_sum);
	return {};
}

vec_GF2EX ToExtendedAlgrotihm2::createPartialPolyVec(const mat_GF2E &A, const std::vector<int> &powers, vec_vec_GF2 &rightSides)
{
	int degree = ExtensionField::instance().degree();
	vec_GF2EX result;
	GF2E gf2e_determinant;
	transposeRS(rightSides);
	
	// compute each partial polynomial
	for (int i = 0; i < degree; i++) {
		vec_GF2E vec_gf2e_x;
		vec_GF2E vec_GF2E_b = getCol(rightSides, i);
		solve(gf2e_determinant, A, vec_gf2e_x, vec_GF2E_b); // A*x=b

		GF2E gf2e_null;
		if (gf2e_determinant == gf2e_null) {
			ERROR("gf2e_determinant == gf2e_null");
			return {};
		}

		// create partial polynomial
		GF2EX gf2ex_p;
		for (int i = 0; i < degree; i++) {
			SetCoeff(gf2ex_p, powers[i], vec_gf2e_x[i]);
		}

		// append to result list
		result.append(gf2ex_p);
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
