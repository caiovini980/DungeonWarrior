#pragma once
#include <memory>

// #include "Map.h"

class CollisionManager;
class ConfigHandler;
class Map;
struct SDL_Renderer;

class MapManager
{
public:
    MapManager(SDL_Renderer* renderer, CollisionManager& collisionManager, ConfigHandler& configHandler);
    ~MapManager() = default;
    
    void Render() const;

    std::shared_ptr<Map> GetMap();
    
private:
    std::shared_ptr<Map> m_Map;
    
};
