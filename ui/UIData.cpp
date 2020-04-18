#include "UIData.h"

std::ostream &operator<<(std::ostream &os, const Header1 &h)
{
	os << h.text;
	return os;
}

std::ostream &operator<<(std::ostream &os, const Header2 &h)
{
	os << h.text;
	return os;
}
