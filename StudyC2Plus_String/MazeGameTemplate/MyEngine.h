#pragma once
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_ttf.lib")
#pragma comment(lib, "SDL2_mixer.lib")

#include <string>
#include "SDL.h"
#include <memory>

class World;

class MyEngine
{
public:
	//MyEngine();
	MyEngine(std::string Title, std::string LevelName, int Width, int Height);
	virtual ~MyEngine();

	void Init(std::string Title, int Width, int Height);
	void Term();

	void Run();

	void Stop();

	void SpawnActor(std::shared_ptr<class Actor> NewActor);
	void DestroyActor(std::shared_ptr<class Actor> DestroyActor);

	void LoadLevel(std::string LoadMapName);
	void SaveLevel(std::string SaveMapName);

	void UnloadLevel();

	inline static SDL_Window* GetWindow() { return MyWindow; }
	inline static SDL_Renderer* GetRenderer() { return MyRenderer; }
	inline static SDL_Event& GetEvent() { return MyEvent; }
	inline static std::unique_ptr<World>& GetWorld() { return CurrentWorld; }

	inline static MyEngine* GetEngine() { return Instance; }

protected:
	void BeginPlay();
	void Tick();
	void Render();
	void Input();

protected:
	bool bIsRunning = true;
	static std::unique_ptr<World> CurrentWorld;

	static SDL_Window* MyWindow;
	static SDL_Renderer* MyRenderer;
	static SDL_Event MyEvent;

	static MyEngine* Instance;
};


#define GEngine MyEngine::GetEngine()


