#pragma once
#include <array>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <vector>

#include "../../Components/Sprite/Sprite.h"
#include "Tile.h"

class Map
{
public:
    Map(SDL_Renderer& renderer);
    ~Map();

    void DrawMap();

private:
    const char* GetTexturePathByID(int i) const;
    
    std::array<std::array<int, 10>, 10> map = {
        {
            {1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
            {1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 0, 0, 1, 1, 1, 1}
        }
    };

    std::vector<Tile> tileMap;

    const float tileSizeX{ 64.0f }; // TODO: Change for default size on some 'config' file
    const float tileSizeY{ 64.0f }; // TODO: Change for default size on some 'config' file
    
    const char* floorTexturePath{ "Assets/Sprites/floor.png" };
    const char* wallTexturePath{ "Assets/Sprites/wall.png" };
    const char* defaultTexturePath{ wallTexturePath };
};
