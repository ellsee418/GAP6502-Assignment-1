#pragma once
#include "Logger.h"
class Profiler
{
public:

protected:

private:

};

//https://stackoverflow.com/questions/700097/memory-allocation-profiling-in-c
// add as base class to any object for instance stats
template<class T>
class InstanceCount
{
	static int s_currentInstanceCount;
	static int s_totalInstanceCount;
	static bool s_hasPrinted;
public:
	InstanceCount() { s_currentInstanceCount++; s_totalInstanceCount++; }
	~InstanceCount() { s_currentInstanceCount--; PrintTotal(); }
	
	static void PrintCurrent()
	{
		LOGA(INFO, "%d current instances of %s, %d bytes each.\n", s_currentInstanceCount, typeid(T).name(), sizeof(T));
	}
	static void PrintTotal()
	{
		if (s_hasPrinted) return;
		LOGA(SYSTEM, "%d total instances of %s, %d bytes total.\n", s_totalInstanceCount, typeid(T).name(), (sizeof(T) * s_totalInstanceCount));
		s_hasPrinted = true;
	}
};

template<class T>
int InstanceCount<T>::s_currentInstanceCount = 0;
template<class T>
int InstanceCount<T>::s_totalInstanceCount = 0;
template<class T>
bool InstanceCount<T>::s_hasPrinted = false;

