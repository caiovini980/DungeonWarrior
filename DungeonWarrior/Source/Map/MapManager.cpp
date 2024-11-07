#include "MapManager.h"
#include <SDL_render.h>

#include "Map.h"

MapManager::MapManager(SDL_Renderer* renderer, CollisionManager& collisionManager, ConfigHandler& configHandler)
    : m_Map(std::make_shared<Map>(renderer, collisionManager, configHandler))
{
}

void MapManager::Render() const
{
    m_Map->DrawMap();
}

std::shared_ptr<Map> MapManager::GetMap()
{
    return m_Map;
}
