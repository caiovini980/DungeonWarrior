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
    const char* GetTexturePathByID(int i) const;

    std::vector<Tile> tileMap;

    std::unique_ptr<TileConfig> tileConfig;
    std::unique_ptr<MapsConfig> mapsConfig;
    
    const char* floorTexturePath{ "Assets/Sprites/floor.png" };
    const char* wallTexturePath{ "Assets/Sprites/wall.png" };
    const char* defaultTexturePath{ wallTexturePath };
};
