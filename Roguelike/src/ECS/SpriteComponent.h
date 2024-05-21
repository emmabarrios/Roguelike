#pragma once
#include "Components.h"

#include "SDL.h"
#include "../TextureManager.h"

class SpriteComponent : public Component {
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
public:
	SpriteComponent() = default;

	SpriteComponent(const char* path) {
		setTexture(path);
	}

	~SpriteComponent() {
		SDL_DestroyTexture(texture);
	}


	void setTexture(const char* path) {
		texture = TextureManager::LoadTexture(path);
	}

	void init() override {
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = 0;
		srcRect.y = 0;

		srcRect.w = 32;
		srcRect.h = 32;

		destRect.w = transform->width;
		destRect.h = transform->height;
	}

	void update() override {
		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);

		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}

	void draw() override {
		TextureManager::Draw(texture, srcRect, destRect);
	}
};