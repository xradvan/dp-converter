#include "SourceLoader.h"
#include "../err/MQAException.h"
#include "../io/FileInputInterface.h"
#include "../io/DefaultFileInput.h"
#include "../io/MQFileInput.h"
#include "../log/Logger.h"

#include <experimental/filesystem>

Sources SourceLoader::loadSources(const Config &c)
{
	INFO("Loading souces from directory: " << c.inputBaseDir);
	std::vector<std::string> entries;
	for (const auto &entry : std::experimental::filesystem::directory_iterator(c.inputBaseDir)) {
		entries.push_back(entry.path());
	}

	Sources result;
	std::shared_ptr<FileInputInterface> input;

	for (const auto &file : c.files) {
		// Input format
		if (file.format == C_FORMAT_DEFAULT)
			input = std::make_shared<DefaultFileInput>();
		else if (file.format == C_FORMAT_MQ)
			input = std::make_shared<MQFileInput>();
		else
			throw MQAException{std::string{"Unknown format: "} + file.format};

		// Traverse subdirectories
		for (const auto &entry : entries) {
			auto path = entry + "/" + file.name;
			auto fileName = path.substr(c.inputBaseDir.rfind("/"), std::string::npos);
			input->setPath(path);
			if (file.type == C_POLY_TYPE_BFP)
				result[file.name].push_back({fileName, input->getBasePolySet()});
			else if (file.type == C_POLY_TYPE_EFP)
				result[file.name].push_back({fileName, input->getExtensionFieldPoly()});
			else
				throw MQAException{std::string{"Unknown type: "} + file.type};
		}
	}
	return result;
}
