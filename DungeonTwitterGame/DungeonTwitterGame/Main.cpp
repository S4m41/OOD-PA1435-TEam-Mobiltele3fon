#include "System.hpp"
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	System system;
	
	if (!system.Initialize())
		return 0;

	system.Run();

	return 0;
}