#include "BasicResultProcessor.h"
#include "Cases.h"
#include "../err/MQAException.h"
#include "../log/Logger.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>

UIData BasicResultProcessor::process(const std::string &caseName, const ResultVector &results)
{
	if (caseName == C_CASES_EF_Rank)
		return processInternal1(caseName, results);
	else if (caseName == C_CASES_EF_BF_multi)
		return processInternal2(caseName, results);
	else if (caseName == C_CASES_BF_multi)
		return processInternal2(caseName, results);
	else if (caseName == C_CASES_BF_EF_rank)
		return processInternal1(caseName, results);
	else
		throw MQAException{std::string{"Unknown case name: "} + caseName};
}

UIData BasicResultProcessor::processInternal1(const std::string &caseName, const ResultVector &results)
{
	UIData data;
	std::vector<int> toProcess;
	std::for_each(results.begin(), results.end(),
		[&toProcess](auto &r) { toProcess.push_back(std::get<int>(r.value)); });

	data.push_back({"", Header2{std::string{"Summary for case: "} + caseName}});
	data.push_back({"Number of quad term matrices", int(toProcess.size())});
	data.push_back({"Min", *std::min_element(toProcess.begin(), toProcess.end())});
	data.push_back({"Max", *std::max_element(toProcess.begin(), toProcess.end())});
	data.push_back({"Average rank", average(toProcess)});
	data.push_back({"Standard deviation", standardDeviation(toProcess)});

	// Details
	data.push_back({"", Separator{}});
	data.push_back({"", Header2{"Details for each file"}});
	std::for_each(results.begin(), results.end(), [&](auto &r) {
		data.push_back({"File", r.file});
		data.push_back({"Ranks", std::get<int>(r.value)});
		data.push_back({"", Separator{}});
	});

	return data;
}

UIData BasicResultProcessor::processInternal2(const std::string &caseName, const ResultVector &results)
{
	std::string minFileName{""};
	int minRank = std::numeric_limits<int>::max();
	std::string maxFileName;
	std::vector<int> toProcess;

	int maxRank = std::numeric_limits<int>::min();
	for (auto &r : results) {
		auto currentRanks = std::get<std::vector<int>>(r.value);
	
		// Avg, std
		toProcess.insert(toProcess.end(), currentRanks.begin(), currentRanks.end());

		// Min
		auto currentMin = std::min_element(currentRanks.begin(), currentRanks.end());
		if (*currentMin < minRank) {
			minRank = *currentMin;
			minFileName = r.file;
		}
		// Max
		auto currentMax = std::max_element(currentRanks.begin(), currentRanks.end());
		if (*currentMax > maxRank) {
			maxRank = *currentMax;
			maxFileName = r.file;
		}
	}
	UIData data;
	data.push_back({"", Header2{std::string{"Summary for case: "} + caseName}});
	data.push_back({"Number of quad term matrices:", int(toProcess.size())});
	std::string minResultText = "Min (" + minFileName + ")";
	data.push_back({minResultText, minRank});
	std::string maxResultText = "Max (" + maxFileName + ")";
	data.push_back({maxResultText, maxRank});
	data.push_back({"Average rank", average(toProcess)});
	data.push_back({"Standard deviation", standardDeviation(toProcess)});


	// Details
	data.push_back({"", Separator{}});
	data.push_back({"", Header2{"Details for each file"}});
	for (auto &r : results) {
		auto ranks = std::get<std::vector<int>>(r.value);
		data.push_back({"File", r.file});
		data.push_back({"Ranks", ranks});
		data.push_back({"Min", *std::min_element(ranks.begin(), ranks.end())});
		data.push_back({"Max", *std::max_element(ranks.begin(), ranks.end())});
		data.push_back({"Average rank", average(toProcess)});
		data.push_back({"Standard deviation", standardDeviation(toProcess)});
		data.push_back({"", Separator{}});
	}

	return data;
}

float BasicResultProcessor::average(const std::vector<int> &vec)
{
	return std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}

float BasicResultProcessor::standardDeviation(const std::vector<int> &vec)
{
	int size = vec.size();
	if (size == 1)
		return 0.0;

	// Avg
	float a = average(vec);

	// Now calculate the variance
	auto variance_func = [&a, &size](float accumulator, const int &val)
	{
		return accumulator + ((val - a)*(val - a) / size);
	};

	return sqrt(std::accumulate(vec.begin(), vec.end(), 0.0, variance_func));
}
