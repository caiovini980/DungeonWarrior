#pragma once

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "../Components/Collision/CollisionManager.h"
#include "../Objects/Input/InputManager.h"
#include "../Objects/Input/InputSystem.h"
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
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;

    // Managers
    std::unique_ptr<InputManager> m_InputManager;
    std::unique_ptr<CollisionManager> m_CollisionManager;
    
    // Systems
    std::unique_ptr<InputSystem> m_InputSystem;

    // Game objects
    std::shared_ptr<Player> m_Player;
    std::unique_ptr<Map> m_Map;
    
    ConfigHandler& m_ConfigHandler;
    WindowConfig& m_Config;
    
    std::string wallTag{"wall"};
    
    int m_Count{0};
    bool m_IsRunning{false};

    void LoadGameObjects();
    void LoadGameSystems();
};
