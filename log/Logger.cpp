#include "Logger.h"
#include "../io/RawOutput.h"

#include <ctime>
#include <iomanip>
#include <sstream>

std::string SimpleDateTime::now()
{
	std::stringstream buffer;
	std::time_t t = std::time(nullptr);
	std::tm tm = *std::localtime(&t);
	buffer << std::put_time(&tm, "%d/%m/%Y %H:%M:%S");
	return buffer.str();
}

Logger::Logger()
: m_output(new RawOutput()) {}

Logger &Logger::instance()
{
	static Logger instance;
	return instance;
}

void Logger::log(const BasePolySet &s)
{
	m_output->putBasePolySet(s);
}

void Logger::log(const ExtensionFieldPoly &p)
{
	m_output->putExtensionFieldPoly(p);
}