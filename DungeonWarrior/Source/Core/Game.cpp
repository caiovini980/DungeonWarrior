#include "Game.h"

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
    player = std::make_shared<Player>(*renderer, configHandler);
    map = std::make_unique<Map>(*renderer, configHandler);

    inputManager = std::make_unique<InputManager>(player);
    
    std::cout << "GameObjects Initialized.\n\n";
}


void Game::LoadGameSystems()
{
    inputSystem = std::make_unique<InputSystem>();
    collisionManager = std::make_unique<CollisionManager>();
    
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

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cerr << "Failed to initialize SDL_image: " << IMG_GetError() << std::endl;
        return;
    }
    std::cout << "SDL_image ... OK\n";

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
    inputManager->HandleInput(state);
    player->Update();

    // check collisions
    // player & walls
    for (auto& tile : map->GetMapTiles())
    {
        // TODO change the way we get this tag, maybe add it to some global file
        if (tile.GetCollider().GetTag() == wallTag)
        {
            if(collisionManager->CheckCollision(player->GetCollider(), tile.GetCollider()))
            {
                std::cout << "Colliding with Wall!\n";
            }
        }
    }
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

