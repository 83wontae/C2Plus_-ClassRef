#include <iostream>
#include "SDL.h"
#include "MyEngine.h"

using namespace std;

int SDL_main(int argc, char* argv[])
{
	cout << "Hello World!" << endl;
	
	unique_ptr<MyEngine> PlayEngine = make_unique<MyEngine>("Maze Game", "Level01.Map", 640, 640);
	PlayEngine->Run();
	PlayEngine = nullptr;
	
	return 0;
}