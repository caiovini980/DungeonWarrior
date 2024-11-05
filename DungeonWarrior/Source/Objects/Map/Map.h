#pragma once
#include <SDL_render.h>
#include <vector>

#include "Tile.h"
#include "../../Utils/ConfigHandler.h"

class Map
{
public:
    Map(SDL_Renderer& renderer, ConfigHandler& configHandler);

    void DrawMap();

    std::vector<Tile>& GetMapTiles();

private:
    const std::string& GetTexturePathByID(int i) const;

    std::vector<Tile> m_Tiles;

    std::unique_ptr<TileConfig> m_TileConfig;
    std::unique_ptr<MapsConfig> m_MapsConfig;
    
    std::unique_ptr<std::string> m_FloorTexturePath{ std::make_unique<std::string>("Assets/Sprites/floor.png") };
    std::unique_ptr<std::string> m_WallTexturePath{ std::make_unique<std::string>("Assets/Sprites/wall.png") };
};
