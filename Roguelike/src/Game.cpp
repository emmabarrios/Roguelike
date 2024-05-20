#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2.h"



Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.addEntity());

Game::Game() {

}

Game::~Game() {

}

void Game::Init(const char* title, int x, int y, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout <<"Subsystems Initialized"<<std::endl;
		window = SDL_CreateWindow(title,  x,  y,  width, height, flags);
		if (window) {
			std::cout <<"Window created"<<std::endl;
		}
		renderer = SDL_CreateRenderer(window, 1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}

	map = new Map();

	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>("assets/images/tank-tiger-right.png"); 

}

void Game::HandleEvents() {
	SDL_Event sdlEvent;

	SDL_PollEvent(&sdlEvent);

	switch (sdlEvent.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
			isRunning = false;
		}
		break;
	}
}

void Game::Update() {
	manager.refresh();
	manager.update();

	player.getComponent<TransformComponent>().position.Add(Vector2(5,0));

	if (player.getComponent<TransformComponent>().position.x > 100) {
		player.getComponent<SpriteComponent>().setTexture("assets/images/player.png");
	}
}

void Game::Render() {
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout<<"Game cleaned"<<std::endl;
}

bool Game::Running() {
	return isRunning;
}
