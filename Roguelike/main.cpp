#include <SDL.h>
#include "Game.h"
#include <iostream>

Game *game = nullptr;


int main(int argc, char* argv[]) {
	game = new Game();

	game->Init("Rogue Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true);

	while (game->Running()) {
		game->HandleEvents();
		game->Update();
		game->Render();
	}

	game->Clean();
	return 0;
}