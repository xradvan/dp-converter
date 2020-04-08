#include "Config.h"
#include "../err/MQAException.h"

#include <fstream>

void Config::load(const std::string &file)
{
	std::ifstream is(file);
	if (!is.is_open()) {
		throw MQAException{std::string{"Could not open configuration file: "} + file};
	}

	std::string str;
	while (std::getline(is, str))
	{
		// skip empty lines and comments
		if (str == "" || !str.find("#"))
			continue;

		auto param = str.substr(0, str.find('='));
		auto value = str.substr(str.find('=') + 1, std::string::npos);

		if (param == "name")
			this->name = value;
		else if (param == "description")
			this->description = value;
		else if (param == "degree")
			this->degree = std::stoi(value);
		else if (param == "input_format")
			this->inputFormat = value;
		else if (param == "input_poly_type")
			this->inputPolyType = value;
		else if (param == "input")
			this->input = value;
		else if (param == "output")
			this->output = value;
		else if (param == "task")
			this->task = value;
		else if (param == "output_format")
			this->outputFormat = value;
		else if (param == "convert_type")
			this->convertType = value;
		else if (param == "cases")
			this->cases = value;
		else
			throw MQAException{std::string{"Could not parse parameter: "} + param};
	}
}
