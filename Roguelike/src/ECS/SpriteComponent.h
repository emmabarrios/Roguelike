#pragma once
#include "Components.h"

#include "SDL.h"
#include "../TextureManager.h"

class SpriteComponent : public Component {
private:
	PositionComponent* position;
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
public:
	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		texture = TextureManager::LoadTexture(path);
	}

	void init() override {
		position = &entity->getComponent<PositionComponent>();

		srcRect.x = 0;
		srcRect.y = 0;

		srcRect.w = 32;
		srcRect.h = 32;

		// why default it on 64x64? I used it with 32x32
		/*destRect.w = 64;
		destRect.h = 64;*/

		destRect.w = 32;
		destRect.h = 32;
	}

	void update() override {
		destRect.x = position->x();
		destRect.y = position->y();
	}

	void draw() override {
		TextureManager::Draw(texture, srcRect, destRect);
	}
};