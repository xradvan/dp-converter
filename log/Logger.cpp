#include "Logger.h"
#include "../io/RawOutput.h"

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