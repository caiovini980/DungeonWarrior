﻿#include "Game.h"

Game::Game(ConfigHandler& configHandler)
     : configHandler(configHandler), config(configHandler.GetWindowConfig())
{
    Init(config.title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, config.width, config.height, false);
}

Game::~Game()
{
}

void Game::LoadGameObjects()
{
    player = std::make_unique<Player>(*renderer, configHandler);
    map = std::make_unique<Map>(*renderer, configHandler);
    
    std::cout << "GameObjects Initialized.\n\n";
}


void Game::LoadGameSystems()
{
    inputSystem = std::make_unique<InputSystem>();
    
    std::cout << "Systems Initialized.\n\n";
}

void Game::Init(const char* title, int xPosition, int yPosition, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error while initializing SDL: " << SDL_GetError() << "\n";
        isRunning = false;
        return;
    }
    
    std::cout << "Subsystems ... OK\n";

    window = SDL_CreateWindow(title, xPosition, yPosition, width, height, flags);
    if (!window)
    {
        std::cerr << "Error while creating a window: " << SDL_GetError() << "\n";
        isRunning = false;
        return;
    }
    
    std::cout << "Window ... OK\n";

    renderer = SDL_CreateRenderer(window, -1, flags);
    if (!renderer)
    {
        std::cerr << "Error while creating a renderer: " << SDL_GetError() << "\n";
        isRunning = false;
        return;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    std::cout << "Renderer ... OK\n";

    isRunning = true;

    LoadGameSystems();
    LoadGameObjects();
}

void Game::HandleEvents()
{
    inputSystem->PrepareForUpdate();
    
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}

void Game::Update()
{
    count++;
    inputSystem->Update();
    const InputState& state = inputSystem->GetState();

    // process input
    player->ProcessInput(state);
    
    player->Update();
}

void Game::Render() const
{
    SDL_RenderClear(renderer);

    // add stuff to render on the screen
    map->DrawMap();
    player->Render();
    
    SDL_RenderPresent(renderer);
}

void Game::Clean() const
{
    player->Destroy();
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    
    std::cout << "Execution cleaned.\n";
}

bool Game::IsGameRunning() const
{
    return isRunning;
}

