#include "MemoryManager.h"
#include "Engine.h"
#include <iostream>
#include "Logger.h"



int main(int argc, char* argv[])
{
	MemoryManager::Get();
	Engine::Get()->Run();
	MemoryManager::Get()->DeInit();

}

// TODO:
