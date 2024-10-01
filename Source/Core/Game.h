#pragma once

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "../Objects/Map/Map.h"
#include "../Objects/Player/Player.h"

class Game
{
public:
    Game();
    ~Game();

    void Init(const char* title, int xPosition, int yPosition, int width, int height, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render() const;
    void Clean() const;

    bool IsGameRunning() const;

private:
    int count{0};
    bool isRunning{false};
    
    SDL_Window* window;
    SDL_Renderer* renderer;

    void LoadGameObjects();

    std::unique_ptr<Player> player;
    std::unique_ptr<Map> map;
};
