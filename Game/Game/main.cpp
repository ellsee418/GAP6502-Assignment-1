#include "Engine.h"
#include <iostream>
#include "Projectile.h"


void operator delete(void* d)
{
	free(d);
}



int main(int argc, char* argv[])
{
	Engine::Get().Run();
}

