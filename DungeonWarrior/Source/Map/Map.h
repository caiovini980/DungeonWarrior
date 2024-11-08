#pragma once
#include <vector>
#include <string>

#include "../Utils/ConfigHandler.h"

class CollisionManager;
class ConfigHandler;
class Tile;
struct SDL_Renderer;

class Map
{
public:
    Map(SDL_Renderer& renderer, CollisionManager& collisionManager, ConfigHandler& configHandler);
    ~Map() = default;
    
    void DrawMap() const;

    std::vector<std::shared_ptr<Tile>>& GetMapTiles();

private:
    const std::string& GetTexturePathByID(int i) const;

    std::vector<std::shared_ptr<Tile>> m_Tiles;

    std::shared_ptr<TileConfig> m_TileConfig;
    std::shared_ptr<MapsConfig> m_MapsConfig;

    std::string m_FloorTexturePath {"Assets/Sprites/floor.png"};
    std::string m_WallTexturePath {"Assets/Sprites/wall.png"};
};
