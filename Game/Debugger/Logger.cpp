#define _CRT_SECURE_NO_WARNINGS 

#include "Logger.h"
#include <memory>
#include <stdexcept>


Logger* Logger::sInstance = nullptr;

Logger::Logger()
	: m_logFileName("Log/log.txt"), m_logFile(nullptr)
{
	Init();
}

void Logger::Init()
{
	m_logFile = fopen(m_logFileName, "w");
	if (!m_logFile)
		throw std::runtime_error("Error opening log file.");
}

void Logger::DeInit()
{
	LOGA(WARNING, "[Logger] Final Clean Up...");
	fclose(m_logFile);
	free(m_logFile);
	delete sInstance;
}

Logger* Logger::Get()
{
	if (!sInstance)
		sInstance = new Logger();
	return sInstance;
}


void Logger::LogToFileAlways(const LogType& type, const char* log, ...)// logs to console and file - forced new line
{
	va_list args;
	va_start(args, log);

	char* out = FormatForFile(log, args);
	LogToConsole(type, log, args);

	if (m_logFile)
	{
		vfprintf(m_logFile, out, args);
		fprintf(m_logFile, "\n");
		fflush(m_logFile);
	}
	free(out);
}

void Logger::LogToFile(const LogType& type, const char* log, ...)
{
	va_list args;
	va_start(args, log);

	char* out = FormatForFile(log, args);
#if defined TEST
	LogToConsole(type, log, args);
#endif

	if (m_logFile)
	{
		vfprintf(m_logFile, out, args);
		fprintf(m_logFile, "\n");
		fflush(m_logFile);
	}
	free(out);
}

void Logger::LogToConsole(const LogType& type, const char* log, ...)// forced new line
{
	va_list args;
	va_start(args, log);
	char* out = AppendColourToString(type, log);
	vprintf(out, args);
	printf("\033[0m");
	va_end(args);
}

void Logger::LogToConsole(const LogType& type, const char* log, va_list& args)// internal only - forced new line
{
	char* out = AppendColourToString(type, log);
	vprintf(out, args);
	va_end(args);
	printf("\033[0m\n");
}

char* Logger::AppendColourToString(const LogType& type, const char* log)
{
	const char* colour;
	switch (type)
	{
	case LogType::ERROR:
		colour = "\033[31m";// RED
		break;
	case LogType::SUCCESS:
		colour = "\033[32m";// GREEN
		break;
	case LogType::WARNING:
		colour = "\033[33m";//YELLOW
		break;
	case LogType::SYSTEM:
		colour = "\033[36m";// BLUE
		break;
	default:
		colour = "\033[1m";// BOLD WHITE
		break;
	}
	size_t len = strlen(colour) + strlen(log) + 1;
	char* out = static_cast<char*>(malloc(len));

	if (out != NULL)
	{
		strcpy(out, colour);
		strcat(out, log);
	}
	return out;
}

char* Logger::FormatForFile(const char* log, const va_list& args)// does not consume va_list arg
{
	va_list copy;
	va_copy(copy, args);// va_list consumed so copy
	int buffer = vsnprintf(nullptr, 0, log, args);// just size
	va_end(copy);
	if (buffer < 0) return {};

	// empty string lit - size of bufffer
	char* out = static_cast<char*>(malloc(buffer));
	vsnprintf(out, (size_t)buffer, log, args);
	return out;
}

void* Logger::operator new(size_t size)
{
	return static_cast<Logger*>(malloc(size));
}

void* Logger::operator new[](size_t size)
{
	return Logger::operator new(size);
}

void Logger::operator delete(void* ptrToDelete)
{
	free(ptrToDelete);
}

void Logger::operator delete[](void* ptrToDelete)
{
	Logger::operator delete(ptrToDelete);
}