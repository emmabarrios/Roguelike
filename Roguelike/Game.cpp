#include "Game.h"


SDL_Texture* playerTexture;
SDL_Rect sourceRectangle;
SDL_Rect destinationRectangle;

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

	// we dont need to keep the surface after finish using it
	SDL_Surface* tempSurface = IMG_Load("tank-panther-right.png");
	playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
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
	count ++;
	destinationRectangle.h = 64;
	destinationRectangle.w = 64;
}

void Game::Render() {
	// Clear render buffer
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTexture, NULL, &destinationRectangle);
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
