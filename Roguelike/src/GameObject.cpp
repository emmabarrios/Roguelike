#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y) {
	this->objectTexture = TextureManager::LoadTexture(textureSheet);

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

	// Why was this fixed by x2? changed to normal, 32x32
	//destinationRectangle.w = sourceRectangle.w * 2;
	//destinationRectangle.h = sourceRectangle.h * 2;

	destinationRectangle.w = sourceRectangle.w;
	destinationRectangle.h = sourceRectangle.h;
}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objectTexture, &sourceRectangle, &destinationRectangle);
}
