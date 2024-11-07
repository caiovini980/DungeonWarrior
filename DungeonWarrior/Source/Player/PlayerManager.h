#pragma once
#include <memory>
#include <SDL_render.h>

#include "../Components/Collision/CollisionManager.h"
#include "../Utils/ConfigHandler.h"

// Forward declarations
class Player;

class PlayerManager
{
public:
    PlayerManager(SDL_Renderer& renderer, CollisionManager& collisionManager, ConfigHandler& configHandler);

    void Update() const;
    void Render() const;
    void Destroy() const;
    
    std::shared_ptr<Player>& GetPlayer();

private:
    std::shared_ptr<Player> m_Player;
};
