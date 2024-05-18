#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer, int x, int y) {
	this->renderer = renderer;
	this->objectTexture = TextureManager::LoadTexture(renderer, textureSheet);

	xPosition = x;
	yPosition = y;
}

void GameObject::Update() {
	
	xPosition ++;
	yPosition ++;

	sourceRectangle.w = 32;
	sourceRectangle.h = 32;
	sourceRectangle.x = 0;
	sourceRectangle.y = 0;

	destinationRectangle.x = xPosition;
	destinationRectangle.y = yPosition;
	destinationRectangle.w = sourceRectangle.w * 2;
	destinationRectangle.h = sourceRectangle.h * 2;
}

void GameObject::Render() {
	SDL_RenderCopy(renderer, objectTexture, &sourceRectangle, &destinationRectangle);
}
