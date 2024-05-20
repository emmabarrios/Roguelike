#pragma once
#include <SDL.h>
#include "Game.h"


class Map {
public:
	Map();
	~Map();
	
	void LoadMap(int arr[20][25]);
	void DrawMap();

private:
	SDL_Rect src;
	SDL_Rect dest;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];

};

