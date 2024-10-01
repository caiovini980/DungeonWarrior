#include <iostream>

#include "./Core/Game.h"

int main(int argc, char* argv[])
{
	const unsigned int FPS = 60;
	const unsigned int frameDelay = 1000/FPS;

	std::unique_ptr<Game> game = std::make_unique<Game>();

	std::cout << "Starting game...\n\n";
	while (game->IsGameRunning())
	{
		Uint32 frameStart = SDL_GetTicks();
		
		game->HandleEvents();
		game->Update();
		game->Render();

		unsigned int frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->Clean();
	
	return 0;
}