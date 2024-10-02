#pragma once

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "../Objects/Map/Map.h"
#include "../Objects/Player/Player.h"
#include "../Utils/ConfigHandler.h"

class Game
{
public:
    Game(ConfigHandler& configHandler);
    ~Game();

    void Init(const char* title, int xPosition, int yPosition, int width, int height, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render() const;
    void Clean() const;

    bool IsGameRunning() const;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    std::unique_ptr<Player> player;
    std::unique_ptr<Map> map;
    
    ConfigHandler& configHandler;
    WindowConfig& config;
    
    int count{0};
    bool isRunning{false};

    void LoadGameObjects();
};
