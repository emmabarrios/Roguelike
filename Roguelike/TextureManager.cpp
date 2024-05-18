#include "TextureManager.h"


SDL_Texture* TextureManager::LoadTexture(SDL_Renderer* renderer, const char* filename) {
	SDL_Surface* tempSurface = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return texture;
}