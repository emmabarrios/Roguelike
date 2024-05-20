#include <SDL.h>
#include "Game.h"
#include <iostream>

Game *game = nullptr;


int main(int argc, char* argv[]) {

	const int FPS = 60;
	const int MILLISECS_PER_FRAME = 1000 / FPS;
	int millisecsPreviousFrame = 0;

	game = new Game();

	game->Init("Rogue Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true);

	while (game->Running()) {

		int millisecsCurrentFrame = SDL_GetTicks();
		if (millisecsCurrentFrame - millisecsPreviousFrame < MILLISECS_PER_FRAME) {
			SDL_Delay(MILLISECS_PER_FRAME - (millisecsCurrentFrame - millisecsPreviousFrame));
			continue;
		}
		millisecsPreviousFrame = millisecsCurrentFrame;

		game->HandleEvents();
		game->Update();
		game->Render();
	}

	game->Clean();
	return 0;
}