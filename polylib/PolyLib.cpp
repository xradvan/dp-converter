#include "PolyLib.h"
#include "../log/Logger.h"

#include <assert.h>
#include <sstream>

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

PolyPowers PolyPowers::getPowers(const NTL::ZZ &n)
{
	PolyPowers powers;
	int *p = &(powers.p1);
	long hw = weight(n);
	if (hw == 2) {
		for (long i = 0; i < NumBits(n); i++) {
			if (bit(n, i)) {
				*p = i;
				p = &(powers.p2);
			}
		}
	}
	else if (hw == 1) {
		for (long i = 0; i < NumBits(n); i++) {
			if (bit(n, i)) {
				*p = i;
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

bool BasePoly::isEmpty()
{
	return NTL::IsZero(quadratic)
		&& NTL::IsZero(linear)
		&& NTL::IsZero(constant);
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

bool BasePolySet::isEmpty()
{
	int degree = ExtensionField::instance().degree();
	for (int i = 0; i < degree; i++) {
		if (!polynomials[i].isEmpty())
			return false;
	}
	return true;
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

void ExtensionFieldPoly::setCoeff(const NTL::ZZ &i, const NTL::GF2E &a)
{
	assert(i >= 0);
	m_rep[i] = a;
}

void ExtensionFieldPoly::setCoeff(const NTL::ZZ &i, long a)
{
	assert(i >= 0);
	m_rep[i] = NTL::conv<NTL::GF2E>(a);
}

NTL::GF2E ExtensionFieldPoly::getCoeff(const NTL::ZZ &i) const
{
	if (m_rep.find(i) == m_rep.end())
		return {};
	else
		return m_rep.at(i);
}

NTL::GF2E ExtensionFieldPoly::getCoeff(long i) const
{
	auto index = NTL::conv<NTL::ZZ>(i);
	if (m_rep.find(index) == m_rep.end())
		return {};
	else
		return m_rep.at(index);
}

NTL::ZZ ExtensionFieldPoly::degree() const
{
	if (!m_rep.empty())
		return (--m_rep.end())->first;
}

bool ExtensionFieldPoly::isEmpty()
{
	return m_rep.empty();
}

bool ExtensionFieldPoly::operator==(const ExtensionFieldPoly &p)
{
	if (m_rep.size() != p.m_rep.size())
		return false;

	auto it1 = m_rep.begin();
	auto it2 = p.m_rep.begin();
	for (; it1 != m_rep.end(); ++it1, ++it2) {
		if (it1->first != it2->first || it1->second != it2->second)
			return false;
	}
	return true;
}

// std::istream &operator>>(std::istream &is, ExtensionFieldPoly &p)
// {
	// std::string s;
	// std::getline(is, s);
	// s = s.substr(1, std::string::npos);
	// s = s.insert(s.length() - 1, " ");
	// size_t pos = 0;
	// std::string token;
	// std::string delimiter = "] ";
	// NTL::ZZ index;
	// NTL::GF2E empty;
	// while ((pos = s.find(delimiter)) != std::string::npos) {
	// 	token = s.substr(0, pos+1);
	// 	s.erase(0, pos + delimiter.length() - 1);
	// 	std::stringstream iss(token);
	// 	NTL::GF2E tmp;
	// 	iss >> tmp;
	// 	if (tmp != empty)
	// 		p.setCoeff(index, tmp);
	// 	index++;
	// }
// }

// std::ostream &operator<<(std::ostream &os, const ExtensionFieldPoly &p)
// {
// 	os << "a";
// 	for (auto it = p.m_rep.begin(); it != p.m_rep.end(); ++it)
// 		if (it->second != NTL::GF2E::zero())
// 			os << it->first;// << " " << it->second << std::endl;
// }

void ExtensionFieldPoly::put(std::ostream &os) const
{
	for (auto it = m_rep.begin(); it != m_rep.end(); ++it)
	if (it->second != NTL::GF2E::zero())
			os << it->first << " " << it->second << std::endl;
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

void Helpers::sort(NTL::Vec<NTL::ZZ> &v)
{
	long size = v.length();
	for (long i = 0; i < size - 1; i++) {
		for (long j = 0; j < size - i - 1; j++) {
			if (v[j+1] < v[j]) {
				NTL::ZZ tmp = v[j+1];
				v.put(j+1, v[j]);
				v.put(j, tmp);
			}
		}
	}
}
