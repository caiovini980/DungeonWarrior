﻿#pragma once

#include <iostream>

#include "Engine/EngineManager.h"

class Obstacle;
class Map;
class Player;
class MapManager;
class InputSystem;
class PlayerManager;
class CollisionManager;
class InputManager;
class ConfigHandler;

struct WindowConfig;
struct SDL_Window;
struct SDL_Renderer;

class Game
{
public:
    Game(ConfigHandler& configHandler);
    ~Game() = default;

    void Init(const char* title, int xPosition, int yPosition, int width, int height, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render() const;
    void Clean() const;

    bool IsGameRunning() const;

private:
    SDL_Window* m_Window;

    // Managers
    std::shared_ptr<InputManager> m_InputManager;
    std::shared_ptr<CollisionManager> m_CollisionManager;
    
    // Systems
    std::shared_ptr<InputSystem> m_InputSystem;

    // Game objects
    Player* m_Player;
    Obstacle* m_Obstacle;
    Map* m_Map;
    
    ConfigHandler& m_ConfigHandler;
    WindowConfig& m_Config;
    
    bool m_IsRunning{false};

    void LoadGameManagers();
    void LoadGameSystems();
};
