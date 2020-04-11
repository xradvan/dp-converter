#include "Config.h"
#include "../err/MQAException.h"
#include "../external/rapidjson/document.h"

#include <fstream>
#include <sstream>

void Config::load(const std::string &file)
{
	std::ifstream is(file);
	if (!is.is_open()) {
		throw MQAException{std::string{"Could not open configuration file: "} + file};
	}

	std::stringstream buffer;
	buffer << is.rdbuf();

	rapidjson::Document doc;
	doc.Parse(buffer.str().c_str());

	this->name = doc["name"].GetString();
	this->description = doc["description"].GetString();
	this->degree = doc["degree"].GetInt();
	this->task = doc["task"].GetString();
	this->inputBaseDir = doc["input"]["input_base_dir"].GetString();
	for (const auto &f : doc["input"]["files"].GetArray()) {
		std::vector<std::string> fc;
		for (const auto &c : f["cases"].GetArray()) {
			fc.push_back(c.GetString());
		}

		this->files.push_back({
			f["name"].GetString(),
			f["type"].GetString(),
			f["format"].GetString(),
			fc
		});
	}
	this->output = doc["output"].GetString();
}
