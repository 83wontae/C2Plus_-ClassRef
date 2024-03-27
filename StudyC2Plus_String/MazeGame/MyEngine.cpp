#include "MyEngine.h"
#include <iostream>
#include <fstream>
#include "Floor.h"
#include "Player.h"
#include "World.h"

using namespace std;

SDL_Window* MyEngine::MyWindow = nullptr;
SDL_Renderer* MyEngine::MyRenderer = nullptr;
SDL_Event MyEngine::MyEvent;
std::unique_ptr<World> MyEngine::CurrentWorld;

MyEngine::MyEngine(string Title, string LevelName, int Width, int Height)
{
	CurrentWorld = std::make_unique<World>();
	bIsRunning = true;

	Init(Title, Width, Height);

	LoadLevel(LevelName);
}

MyEngine::~MyEngine()
{
	CurrentWorld = nullptr;
	bIsRunning = false;

	Term();
}

void MyEngine::Init(std::string Title, int Width, int Height)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL_Init Error :" << SDL_GetError() << endl;
	}

	MyWindow = SDL_CreateWindow(Title.c_str(), 100, 100, Width, Height, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
}

void MyEngine::Term()
{
	//TTF_Quit();

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
}

void MyEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}
void MyEngine::SpawnActor(std::shared_ptr<class Actor> NewActor)
{
	CurrentWorld->SpawnActor(NewActor);
}
void MyEngine::DestroyActor(std::shared_ptr<class Actor> DestroyActor)
{
	CurrentWorld->DestroyActor(DestroyActor);
}
void MyEngine::Input()
{
	SDL_PollEvent(&MyEvent);

	//�������� �⺻ ó�� �ϴ� �̺�Ʈ
	switch (MyEvent.type)
	{
	case SDL_QUIT:
		bIsRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (MyEvent.key.keysym.sym)
		{
		case SDLK_q:
			bIsRunning = false;
			break;
		}
		break;
	}
}
void MyEngine::Tick()
{
	
}
void MyEngine::Render()
{
	//ȭ�������
	SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(MyRenderer);
	//�׸� ����Ʈ �غ�
//PreRender(�׸� �غ�, �׸� ��ü ��ġ)

	CurrentWorld->Render();

	//GPU�� �׷���
//Render
	SDL_RenderPresent(MyRenderer);
}

void MyEngine::LoadLevel(std::string LoadMapName)
{
	//SpawnActor(std::make_shared<BGM>("data/bgm.mp3"));

	std::ifstream MapFile(LoadMapName);
	int X = 0;
	int Y = 0;

	while (!MapFile.eof())
	{
		char ReadData = MapFile.get();
		switch (ReadData)
		{
		case '\n':
			X = 0;
			Y++;
			continue;
		case 'P':
			SpawnActor(std::make_shared<Floor>(X, Y, "data/floor.bmp"));
			SpawnActor(std::make_shared<Player>(X, Y, "data/test.bmp"));
			break;
		default:
			SpawnActor(std::make_shared<Floor>(X, Y, "data/floor.bmp"));
			break;
		}

		/*
		switch (ReadData)
		{
		case '\n':
			X = 0;
			Y++;
			continue;
		case ' ':
			SpawnActor(std::make_shared<Floor>(X, Y, "data/floor.bmp"));
			break;
		case '*':
			SpawnActor(std::make_shared<Wall>(X, Y, "data/wall.bmp"));
			SpawnActor(std::make_shared<Floor>(X, Y, "data/floor.bmp"));
			break;
		case 'P':
			SpawnActor(std::make_shared<Player>(X, Y, "data/test.bmp"));
			SpawnActor(std::make_shared<Floor>(X, Y, "data/floor.bmp"));
			break;
		case 'G':
			SpawnActor(std::make_shared<Goal>(X, Y, "data/coin.bmp"));
			SpawnActor(std::make_shared<Floor>(X, Y, "data/floor.bmp"));
			break;
		case 'E':
			SpawnActor(std::make_shared<Monster>(X, Y, "data/slime.bmp"));
			SpawnActor(std::make_shared<Floor>(X, Y, "data/floor.bmp"));
			break;
		}
		*/
		X++;
	}

	MapFile.close();
}