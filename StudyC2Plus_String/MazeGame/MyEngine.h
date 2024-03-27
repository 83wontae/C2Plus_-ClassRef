#pragma once

#include <string>
#include "SDL.h"
#include <memory>

class World;

class MyEngine
{
public:
	MyEngine(std::string Title, std::string LevelName, int Width, int Height);
	virtual ~MyEngine();

	void Init(std::string Title, int Width, int Height);
	void Term();

	void Run();

	void SpawnActor(std::shared_ptr<class Actor> NewActor);
	void DestroyActor(std::shared_ptr<class Actor> DestroyActor);

	void LoadLevel(std::string LoadMapName);

	inline static SDL_Renderer* GetRenderer() { return MyRenderer; }

	inline static std::unique_ptr<World>& GetWorld() { return CurrentWorld; }

private:

protected:
	void Input();
	void Tick();
	void Render();

protected:
	bool bIsRunning = true;
	static std::unique_ptr<World> CurrentWorld;

	static SDL_Window* MyWindow;
	static SDL_Renderer* MyRenderer;
	static SDL_Event MyEvent;
};

