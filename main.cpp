#include <iostream>
#include <NTL/vec_GF2.h>

int main(int argc, char *argv[])
{
	NTL::vec_GF2 v;
	v = NTL::random_vec_GF2(10);
	std::cout << v << std::endl;
}
