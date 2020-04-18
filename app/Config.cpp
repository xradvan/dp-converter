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

	this->name = doc["name"].IsNull() ? C_NOT_SET : doc["name"].GetString();
	this->description = doc["description"].IsNull() ? C_NOT_SET : doc["description"].GetString();
	this->degree = doc["degree"].IsNull() ? -1 : doc["degree"].GetInt();
	this->task = doc["task"].IsNull() ? C_NOT_SET : doc["task"].GetString();
	this->toExtensionAlg = doc.HasMember("to_extension_alg") ? doc["to_extension_alg"].GetString() : C_CONVERT_TO_EXT_ALG1;
	// Analyzer part
	if (!doc["input"].IsNull() && doc["input"].HasMember("input_base_dir")) {
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
	// Converter part
	else {
		this->coversionType = doc["coversion_type"].GetString();
		{
			File f;
			f.name = doc["input"]["file"].GetString();
			f.format = doc["input"]["format"].GetString();
			this->inputFile = f;
		}
		{
			File f;
			f.name = doc["output"]["file"].GetString();
			f.format = doc["output"]["format"].GetString();
			this->outputFile = f;
		}
	}
}
