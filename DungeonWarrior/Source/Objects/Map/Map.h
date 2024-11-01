#pragma once
#include <SDL_render.h>
#include <vector>

#include "Tile.h"
#include "../../Utils/ConfigHandler.h"

class Map
{
public:
    Map(SDL_Renderer& renderer, ConfigHandler& configHandler);
    ~Map();

    void DrawMap();

private:
    const char* GetTexturePathByID(int i) const;

    std::vector<Tile> tileMap;

    TileConfig tileConfig;
    MapsConfig mapsConfig;
    
    const char* floorTexturePath{ "Assets/Sprites/floor.png" };
    const char* wallTexturePath{ "Assets/Sprites/wall.png" };
    const char* defaultTexturePath{ wallTexturePath };
};
