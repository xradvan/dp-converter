#pragma once

#include "ResultProcessorInterface.h"
#include <utility>

class BasicResultProcessor : public ResultProcessorInterface
{
public:
	UIData process(const std::string &caseName, const ResultVector &results) override;

private:
	UIData processInternal1(const std::string &caseName, const ResultVector &results);
	UIData processInternal2(const std::string &caseName, const ResultVector &results);

	float average(const std::vector<int> &vec);
	float standardDeviation(const std::vector<int> &vec);
};
