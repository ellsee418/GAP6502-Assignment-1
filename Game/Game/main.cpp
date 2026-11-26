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
// make sure all new/delete is using MM overloads
// change printfs to be LOGs
// fix MM reinit after DeInit()
