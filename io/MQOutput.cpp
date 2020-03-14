#include "MQOutput.h"

void MQOutput::putBasePolySet(const BasePolySet &s)
{
	int degree = ExtensionField::instance().degree();
	std::cout << std::endl;
	std::cout << "Galois Field : GF(2)" << std::endl;
	std::cout << "Number of variables (n) : " << degree << std::endl;
	std::cout << "Number of equations (m) : " << degree << std::endl;
	std::cout << "Seed : 0" << std::endl;
	std::cout << "Order : Graded reverse lexicographic order" << std::endl;
	std::cout << "******************************************" << std::endl;

	for (int i = 0; i < degree; i++) {
		for (int j = 0; j < degree; j++)
			for (int k = 0; k <= j; k++)
				std::cout << s.polynomials[i].quadratic[k][j] << " ";

		for (int j = 0; j < degree; j++)
			std::cout << s.polynomials[i].linear[j] << " ";

		std::cout << s.polynomials[i].constant << ";" << std::endl;
	}
	std::cout << std::endl;
}

void MQOutput::putExtensionFieldPoly(const ExtensionFieldPoly &p)
{
	// NOT IMPLEMENTED
}
