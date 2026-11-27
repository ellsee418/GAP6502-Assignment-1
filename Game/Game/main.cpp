#include "MemoryManager.h"
#include "Engine.h"
#include <iostream>



int main(int argc, char* argv[])
{
	MemoryManager::Get();
	Engine::Get()->Run();
	MemoryManager::Get()->DeInit();
}

// TODO:
// triple quardruple check that new/delete is always MM
// LOGC ignore colours