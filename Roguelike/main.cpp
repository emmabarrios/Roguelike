#include <SDL.h>
#include "Game.h"
#include <iostream>

Game *game = nullptr;


int main() {
	game = new Game();

	while (game->Running()) {
		game->HandleEvents();
		game->Update();
		game->Render();
	}

	game->Clean();
	return 0;
}