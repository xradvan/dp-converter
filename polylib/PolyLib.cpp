#include "PolyLib.h"
#include "../log/Logger.h"

#include <assert.h>

#define MIN_DEGREE 2

ExtensionField &ExtensionField::instance()
{
	static ExtensionField instance;
	return instance;
}

void ExtensionField::init(int degree)
{
	assert(degree >= MIN_DEGREE);

	INFO("Extension field of degree: " << degree);
	m_degree = degree;

	PrimitivePoly p = PrimitivePolyFactory::createPolyOfDegree(m_degree);
	m_polynomial = p;
	NTL::GF2E::init(p.rep);
}

void ExtensionField::init(int degree, const PrimitivePoly &polynomial)
{
	assert(degree >= MIN_DEGREE);

	m_degree = degree;
	m_polynomial = polynomial;
}

int ExtensionField::degree() const
{
	assert(m_degree >= MIN_DEGREE);
	return m_degree;
}

PrimitivePoly ExtensionField::polynomial() const
{
	return m_polynomial;
}

PolyPowers::PolyPowers() : p1(NOT_SET), p2(NOT_SET) {}

PolyPowers PolyPowers::getPowers(int n)
{
	PolyPowers powers;
	NTL::vec_GF2 v = Helpers::intToVec(n);
	long hw = weight(v);
	int *p = &(powers.p1);
	if (hw == 2) {
		for (int i = 0; i < v.length(); i++) {
			if (v[i] == 1) {
				*p = i;
				p = &(powers.p2);
			}
		}
	} else if (hw == 1) {
		for (int i = 0; i < v.length(); i++) {
			if (v[i] == 1) {
				powers.p1 = i;
			}
		}
	}
	return powers;
}

BasePoly::BasePoly()
{
	int degree = ExtensionField::instance().degree();
	quadratic.SetDims(degree, degree);
	linear.SetLength(degree);
}

bool BasePoly::operator==(const BasePoly &p)
{
	return this->constant == p.constant
		&& this->linear == p.linear
		&& this->quadratic == p.quadratic;
}

bool BasePoly::operator!=(const BasePoly &p)
{
	return this->constant != p.constant
		|| this->linear != p.linear
		|| this->quadratic != p.quadratic;
}

std::ostream &operator<<(std::ostream &os, const BasePoly &p)
{
	int degree = ExtensionField::instance().degree();
	os << "[";
	for (int i = 0; i < degree; i++) {
		os << p.quadratic[i];
	}
	os << "] ";

	os << p.linear << " " << p.constant;
	return os;
}

BasePolySet::BasePolySet()
{
	int degree = ExtensionField::instance().degree();
	polynomials.SetLength(degree);
}

bool BasePolySet::operator==(const BasePolySet &s)
{
	int degree = ExtensionField::instance().degree();
	for (int i = 0; i < degree; i++) {
		if (this->polynomials[i] != s.polynomials[i])
			return false;
	}
	return true;
}

bool BasePolySet::operator!=(const BasePolySet &s)
{
	int degree = ExtensionField::instance().degree();
	for (int i = 0; i < degree; i++) {
		if (this->polynomials[i] == s.polynomials[i])
			return false;
	}
	return true;
}

bool ExtensionFieldPoly::operator==(const ExtensionFieldPoly &p)
{
	return this->rep == p.rep;
}

bool ExtensionFieldPoly::operator!=(const ExtensionFieldPoly &p)
{
	return this->rep != p.rep;
}

NTL::vec_GF2 Helpers::intToVec(int value)
{
	int degree = ExtensionField::instance().degree();
	NTL::vec_GF2 v;
	v.SetLength(degree);

	for (int i = 0; i < degree; i++) {
		v[i] = value & 0x1;
		value >>= 1;
	}
	return v;
}

void Helpers::setAlphas(NTL::vec_GF2E &vec, long p)
{
	int degree = ExtensionField::instance().degree();
	for (int i = 0; i < degree; i++) {
		NTL::GF2E temp;
		temp.LoopHole().SetLength(i + 1);
		temp.LoopHole()[i] = 1;

		NTL::power(temp, temp, pow(2, p));
		vec.append(temp);
	}
}

NTL::vec_GF2 Helpers::gf2eToVec(const NTL::GF2E &v)
{
	NTL::GF2E u(v);
	NTL::vec_GF2 result;
	int degree = ExtensionField::instance().degree();
	result.SetLength(degree);

	for (int i = 0; i < degree; i++) {
		result[i] = u.LoopHole()[i];
	}
	return result;
}

NTL::vec_GF2 Helpers::eval(const BasePolySet &poly, const NTL::vec_GF2 &value)
{
	BasePolySet workPoly(poly);
	int degree = ExtensionField::instance().degree();
	NTL::vec_GF2 result;
	result.SetLength(degree);

	for (int i = 0; i < degree; i++)
		for (int j = 0; j < degree; j++)
			if (value[j] == 0) {
				workPoly.polynomials[i].linear[j] = 0;

				for (int k = 0; k < degree; k++) {
					workPoly.polynomials[i].quadratic[j][k] = 0;
					workPoly.polynomials[i].quadratic[k][j] = 0;
				}
			}

	for (int i = 0; i < degree; i++) {
		result[i] += workPoly.polynomials[i].constant;
		for (int j = 0; j < degree; j++) {
			result[i] += workPoly.polynomials[i].linear[j];
			for (int k = 0; k < degree; k++)
				result[i] += workPoly.polynomials[i].quadratic[j][k];
		}
	}

	return result;
}