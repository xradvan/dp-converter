#include "Analyzer.h"
#include "Cases.h"

#include <thread>

Result CasesFunc::EF_QuadFormRank(const Config &c)
{

	std::this_thread::sleep_for(std::chrono::seconds(2));
	return {"EF_QuadFormRank", 1};
}

Result CasesFunc::BF_QuadTermRank(const Config &c)
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return {"BF_QuadTermRank", 2};
}
