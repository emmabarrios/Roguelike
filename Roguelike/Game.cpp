#include "Game.h"


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
}

void Game::HandleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	}
}

void Game::Update() {
}

void Game::Render() {
	// Clear render buffer
	SDL_RenderClear(renderer);

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
