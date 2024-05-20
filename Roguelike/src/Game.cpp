#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

GameObject* player;
GameObject* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

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

	player = new GameObject("assets/images/tank-tiger-right.png", 0, 0);
	enemy = new GameObject("assets/images/player.png", 50, 50);
	map = new Map();

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
	player->Update();
	enemy->Update();
}

void Game::Render() {
	SDL_RenderClear(renderer);
	map->DrawMap();
	player->Render();
	enemy->Render();
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
