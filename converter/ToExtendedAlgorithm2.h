/**
 *@file ToExtendedAlgorithm2.h
 *@author Bc. Peter Radvan
 *@brief The second algorithm to convert base polynomial to extension field representation [Kipnis-Shamir]
 *@version 0.1
 *
 *@copyright Copyright (c) 2020
 *
 */
#pragma once

#include "ToExtendedAlgInterface.h"
#include <NTL/mat_GF2E.h>
#include <NTL/vec_GF2E.h>
#include <vector>

class ToExtendedAlgrotihm2 : public ToExtendedAlgInterface
{
public:
	ExtensionFieldPoly convert(const BasePolySet &toConvert) override;

private:
	NTL::vec_GF2EX createPartialPolyVec(const NTL::mat_GF2E &A,
		const std::vector<int> &powers,
		NTL::vec_vec_GF2 &rightSides);

	void transposeRS(NTL::vec_vec_GF2 &rightSides);
	NTL::vec_GF2E getCol(const NTL::vec_vec_GF2 &rightSides_t, int index);
};
