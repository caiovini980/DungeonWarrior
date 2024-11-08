#include "Game.h"
#include <SDL_image.h>

#include "../Map/MapManager.h"
#include "../Objects/Input/InputSystem.h"
#include "../Components/Collision/CollisionManager.h"
#include "../Objects/Input/InputManager.h"
#include "../Player/PlayerManager.h"

Game::Game(ConfigHandler& configHandler)
     : m_ConfigHandler(configHandler), m_Config(configHandler.GetWindowConfig())
{
    Init(m_Config.title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Config.width, m_Config.height, false);
}

void Game::LoadGameSystems()
{
    m_InputSystem = std::make_shared<InputSystem>();
    
    std::cout << "Systems Initialized.\n\n";
}

void Game::LoadGameManagers()
{
    m_CollisionManager = std::make_shared<CollisionManager>();
    m_PlayerManager = std::make_shared<PlayerManager>(*m_Renderer, *m_CollisionManager, m_ConfigHandler);
    m_MapManager = std::make_shared<MapManager>(*m_Renderer, *m_CollisionManager, m_ConfigHandler);
    
    m_InputManager = std::make_shared<InputManager>(m_PlayerManager->GetPlayer());
    
    std::cout << "Managers Initialized.\n\n";
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
        m_IsRunning = false;
        return;
    }
    
    std::cout << "Subsystems ... OK\n";

    m_Window = SDL_CreateWindow(title, xPosition, yPosition, width, height, flags);
    if (!m_Window)
    {
        std::cerr << "Error while creating a window: " << SDL_GetError() << "\n";
        m_IsRunning = false;
        return;
    }
    
    std::cout << "Window ... OK\n";

    m_Renderer = SDL_CreateRenderer(m_Window, -1, flags);
    if (!m_Renderer)
    {
        std::cerr << "Error while creating a renderer: " << SDL_GetError() << "\n";
        m_IsRunning = false;
        return;
    }

    SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
    std::cout << "Renderer ... OK\n";

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cerr << "Failed to initialize SDL_image: " << IMG_GetError() << "\n";
        return;
    }
    std::cout << "SDL_image ... OK\n";

    m_IsRunning = true;

    LoadGameSystems();
    LoadGameManagers();
}

void Game::HandleEvents()
{
    m_InputSystem->PrepareForUpdate();
    
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            m_IsRunning = false;
            break;

        default:
            break;
    }
}

void Game::Update()
{
    m_Count++;
    m_InputSystem->Update();
    const InputState& state = m_InputSystem->GetState();

    // process input
    m_InputManager->HandleInput(state);
    m_PlayerManager->Update();

    // check collisions
    // player & walls
    // for (auto& tile : m_Map->GetMapTiles())
    // {
    //     if (tile.GetCollider().GetCollisionType() == CollisionTypes::WALL)
    //     {
    //         if(m_CollisionManager->CheckCollision(m_Player->GetCollider(), tile.GetCollider()))
    //         {
    //             std::cout << "COLLIDING!\n";
    //         }
    //     }
    // }
}

void Game::Render() const
{
    SDL_RenderClear(m_Renderer);

    // add stuff to render on the screen
    m_MapManager->Render();
    m_PlayerManager->Render();
    
    SDL_RenderPresent(m_Renderer);
}

void Game::Clean() const
{
    m_PlayerManager->Destroy();
    
    SDL_DestroyWindow(m_Window);
    SDL_DestroyRenderer(m_Renderer);
    SDL_Quit();
    
    std::cout << "Execution cleaned.\n";
}

bool Game::IsGameRunning() const
{
    return m_IsRunning;
}

