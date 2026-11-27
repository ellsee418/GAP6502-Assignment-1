#pragma once

// not the best solution to Logger dependency
// didnt want logger to be in MM but it still requires linking to static lib so...
// this way at least its seperate from TS and MM but both are linked

#include <stdarg.h>
#include <stdio.h>

enum LogType
{
	INFO = 0,
	ERROR,
	WARNING,
	SUCCESS,
	SYSTEM
};

class Logger
{
public:
	~Logger() = default;
	static Logger* Get();
	void Init();
	void DeInit();

	void LogToFileAlways(const LogType& type, const char* log, ...);
	void LogToFile(const LogType& type, const char* log, ...);
	void LogToConsole(const LogType& type, const char* log, ...);

	char* AppendColourToString(const LogType& type, const char* log);

	Logger(Logger& other) = delete;
	void operator=(const Logger&) = delete;
private:
	const char* m_logFileName;
	FILE* m_logFile;

	void* operator new(size_t size);
	void* operator new[](size_t size);
	void operator delete(void* ptrToDelete);
	void operator delete[](void* ptrToDelete);
protected:
	Logger();
	static Logger* sInstance;
	void LogToConsole(const LogType& type, const char* log, va_list& args);
	char* FormatForFile(const char* log, const va_list& args);
};

#ifdef _DEBUG
#define LOGA(x, y, ...) Logger::Get()->LogToFileAlways(x, y, __VA_ARGS__) // console ALWAYS file ALWAYS
#define LOGF(x, y, ...) Logger::Get()->LogToFile(x, y, __VA_ARGS__)		// console !TEST  file ALWAYS
#define LOGC(x, y, ...) Logger::Get()->LogToConsole(x, y, __VA_ARGS__)	// console ALWAYS file NEVER
#endif

#ifndef _DEBUG
#define LOGF(x, y, ...)
#define LOGA(x, y, ...)
#define LOGC(x, y, ...)
#endif
