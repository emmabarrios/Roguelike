#pragma once
#include "Game.h"

class GameObject {
public:
	GameObject(const char* textureSheet, SDL_Renderer* renderer, int x, int y);
	~GameObject() = default;

	void Update();
	void Render();

private:
	int xPosition;
	int yPosition;

	SDL_Texture* objectTexture;
	SDL_Rect sourceRectangle;
	SDL_Rect destinationRectangle;
	SDL_Renderer* renderer;
};

