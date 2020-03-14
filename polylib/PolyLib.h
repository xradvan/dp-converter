/**
 * @file PolyLib.h
 * @author Bc. Peter Radvan
 * @brief Set of classes and structs to represent base and extension field polynomials
 * @warning ExtensionField::instance().init(degree) must be called first!
 * @version 0.1
 *
 * @copyright Copyright (c) 2020
 *
 */
#pragma once

#include <NTL/GF2.h>
#include <NTL/GF2EX.h>
#include <NTL/mat_GF2.h>
#include <NTL/vec_GF2.h>
#include <NTL/vec_GF2E.h>

/**
 * @brief Primitive polynomial to build extension field
 * Internal representation by NTL::GF2X
 */
struct PrimitivePoly
{
	NTL::GF2X rep;
};


/**
 * @brief Factory for creating primitive polynomials of degree n
 *
 */
struct PrimitivePolyFactory
{
	static PrimitivePoly createPolyOfDegree(int n);
};

/**
 * @brief Extension field representation
 * Implemented as a singleton.
 *
 * @warning Initalization must be called at first:
 * ExtensionField::instance().init(degree);
 *
 */
class ExtensionField
{
public:
	static ExtensionField &instance();
	void init(int degree);
	void init(int degree, const PrimitivePoly &polynomial);

	int degree() const;
	PrimitivePoly polynomial() const;

public:
	ExtensionField(ExtensionField const&) = delete;
	void operator=(ExtensionField const&) = delete;

private:
	ExtensionField() = default;

private:
	int m_degree;
	PrimitivePoly m_polynomial;
};

/**
 * @brief Structure to represent powers in univariate polynomial over extension field
 *
 */
struct PolyPowers
{
	int p1;
	int p2;
	PolyPowers();

	static PolyPowers getPowers(int n);
	enum { NOT_SET = -1 };
};

/**
 * @brief Structure to represent multivariate polynomial over base field
 *
 */
struct BasePoly
{
	NTL::mat_GF2 quadratic;
	NTL::vec_GF2 linear;
	NTL::GF2 constant;

	BasePoly();
	friend std::ostream &operator<<(std::ostream &os, const BasePoly &p);
};

/**
 * @brief Structure to represent set of multivariate polynomials over base field
 *
 */
struct BasePolySet
{
	NTL::Vec<BasePoly> polynomials;
	BasePolySet();
};

/**
 * @brief Structure to represent polynomial over extension field
 * @todo add interface (ctor, << ... ), builder pattern?
 */
struct ExtensionFieldPoly
{
	NTL::GF2EX rep;
};

/**
 * @brief Helper functions
 *
 */
struct Helpers
{
	static NTL::vec_GF2 intToVec(int value);
	static void setAlphas(NTL::vec_GF2E &vec, long p);
	static NTL::vec_GF2 gf2eToVec(const NTL::GF2E &v);
	static NTL::vec_GF2 eval(const BasePolySet &poly, const NTL::vec_GF2 &value);
};
