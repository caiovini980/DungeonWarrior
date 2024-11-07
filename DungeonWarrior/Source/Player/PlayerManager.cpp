#include "PlayerManager.h"

#include "Player.h"

PlayerManager::PlayerManager(SDL_Renderer& renderer, CollisionManager& collisionManager, ConfigHandler& configHandler)
     : m_Player(std::make_shared<Player>(renderer, collisionManager, configHandler))
{
}

void PlayerManager::Update() const
{
    m_Player->Update();
}

void PlayerManager::Render() const
{
    m_Player->Render();
}

void PlayerManager::Destroy() const
{
    m_Player->Destroy();
}

std::shared_ptr<Player>& PlayerManager::GetPlayer()
{
    return m_Player;
}
