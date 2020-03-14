#pragma once

#include <NTL/GF2.h>
#include <NTL/GF2EX.h>
#include <NTL/mat_GF2.h>
#include <NTL/vec_GF2.h>
#include <NTL/vec_GF2E.h>

// Primitive polynomial to build extension field
// Internal representation by NTL::GF2X
// TODO
struct PrimitivePoly
{
	NTL::GF2X rep;
};

// TODO
struct PrimitivePolyFactory
{
	static PrimitivePoly createPolyOfDegree(int n);
};

// Extension field representation
class ExtensionField
{
public:
	static ExtensionField &instance();
	void init(int degree); // TODO implement (auto choose polynomial of that deg)
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

// Structure to represent powers in univariate polynomial
// over extension field
struct PolyPowers
{
	int p1;
	int p2;
	PolyPowers();

	static PolyPowers getPowers(int n);
	enum { NOT_SET = -1 };
};

// Structure to represent multivariate polynomial over base field
struct BasePoly
{
	NTL::mat_GF2 quadratic;
	NTL::vec_GF2 linear;
	NTL::GF2 constant;

	BasePoly();
	friend std::ostream &operator<<(std::ostream &os, const BasePoly &p);
};

// Structure to represent set of multivariate polynomials over base field
struct BasePolySet
{
	NTL::Vec<BasePoly> polynomials;
	BasePolySet();
};

// Structure to represent polynomial over extension field
// TODO add interface (ctor, << ... ), builder pattern?
// TODO enforce ExtensionField::init
struct ExtensionFieldPoly
{
	NTL::GF2EX rep;
};

// Helper functions
struct Helpers
{
	// TODO check
	static NTL::vec_GF2 intToVec(int value);
	static void setAlphas(NTL::vec_GF2E &vec, long p);
	static NTL::vec_GF2 gf2eToVec(const NTL::GF2E &v);
	static NTL::vec_GF2 eval(const BasePolySet &poly, const NTL::vec_GF2 &value);
};
