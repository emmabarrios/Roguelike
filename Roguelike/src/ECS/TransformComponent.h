#pragma once
#include "Components.h"
#include "../Vector2.h"

class TransformComponent : public Component {

public:

	Vector2 position;
	Vector2 velocity;

	int speed = 3;

	int scale = 1;
	int height = 32;
	int width = 32;

	TransformComponent() {
		position.Zero();
	}

	TransformComponent(float x, float y) {
		position.Zero();
	}

	TransformComponent(int sc) {
		position.Zero();
		scale = sc;
	}

	TransformComponent(float x, float y, int h, int w, int sc) {
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
	}

	void update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

	void init() override {
		velocity.Zero();
	}
};