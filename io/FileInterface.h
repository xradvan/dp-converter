#pragma once

#include <string>

class FileInterface
{
public:
	virtual ~FileInterface() = default;
	virtual void setPath(const std::string &path) = 0;
};
