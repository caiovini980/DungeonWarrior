#include <iostream>

#include "./Core/Game.h"
#include "Utils/ConfigHandler.h"

int main(int argc, char* argv[])
{
	const unsigned int FPS = 60;
	const unsigned int frameDelay = 1000/FPS;

	// Load config files
	std::shared_ptr<ConfigHandler> configHandler = std::make_shared<ConfigHandler>();
	std::unique_ptr<Game> game = std::make_unique<Game>(*configHandler);
	
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
