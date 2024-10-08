#pragma once
#include <array>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <vector>

#include "../../Components/Sprite/Sprite.h"
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
    
    // std::array<std::array<int, 15>, 10> map = { // X, Y
    //     {
    //         {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    //         {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    //         {1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    //         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    //         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    //         {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1},
    //         {1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
    //         {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
    //         {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    //         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    //     }
    // };

    std::vector<Tile> tileMap;

    TileConfig tileConfig;
    MapsConfig mapsConfig;
    
    const char* floorTexturePath{ "Assets/Sprites/floor.png" };
    const char* wallTexturePath{ "Assets/Sprites/wall.png" };
    const char* defaultTexturePath{ wallTexturePath };
};
