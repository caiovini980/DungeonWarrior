#include "Game.h"
#include <SDL_image.h>

#include "Engine/EngineManager.h"
#include "Engine/Components/Collision/CollisionManager.h"

#include "Game/Input/InputSystem.h"
#include "Game/Input/InputManager.h"
#include "Game/Player/Player.h"
#include "Game/Map/Map.h"
#include "Game/Obstacles/Obstacle.h"

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
    auto gameManager = EngineManager::GetInstance();
    
    m_CollisionManager = std::make_shared<CollisionManager>();
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
    
    // Initialize GameManager
    EngineManager& gameManager = EngineManager::GetInstance();
    gameManager.SetRenderer(SDL_CreateRenderer(m_Window, -1, flags));
    
    if (!gameManager.GetRenderer())
    {
        std::cerr << "Error while creating a renderer: " << SDL_GetError() << "\n";
        m_IsRunning = false;
        return;
    }
    
    SDL_SetRenderDrawColor(gameManager.GetRenderer(), 255, 255, 255, 255);
    std::cout << "Renderer ... OK\n";

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cerr << "Failed to initialize SDL_image: " << IMG_GetError() << "\n";
        return;
    }
    std::cout << "SDL_image ... OK\n";

    m_IsRunning = true;

    LoadGameSystems();
    // LoadGameManagers();
    
    m_Map = &gameManager.SpawnGameObject<Map>();
    m_Map->SetupMap(m_ConfigHandler.GetMapsConfig(), m_ConfigHandler.GetTileConfig());
    
    m_Player = &gameManager.SpawnGameObject<Player>();
    m_Player->SetupPlayer(m_ConfigHandler.GetPlayerConfig());

    m_Obstacle = &gameManager.SpawnGameObject<Obstacle>();
    m_Obstacle->SetupObstacle(m_ConfigHandler.GetObstacleConfig());

    m_InputManager = std::make_shared<InputManager>(m_Player);
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
    m_InputSystem->Update();
    const InputState& state = m_InputSystem->GetState();

    // process input
    m_InputManager->HandleInput(state);
    EngineManager::GetInstance().Update();
}

void Game::Render() const
{
    SDL_RenderClear(EngineManager::GetInstance().GetRenderer());

    EngineManager::GetInstance().Render();
    
    SDL_RenderPresent(EngineManager::GetInstance().GetRenderer());
}

void Game::Clean() const
{
    SDL_DestroyWindow(m_Window);
    SDL_DestroyRenderer(EngineManager::GetInstance().GetRenderer());
    SDL_Quit();
    
    std::cout << "Execution cleaned.\n";
}

bool Game::IsGameRunning() const
{
    return m_IsRunning;
}

