#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Game {
public:
	Game();
	~Game();

	void Init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	bool Running();

private:
	int count;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
	
};

