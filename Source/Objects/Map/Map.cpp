#include "Map.h"

Map::Map(SDL_Renderer& renderer, ConfigHandler& configHandler)
    : tileConfig(configHandler.GetTileConfig()), mapsConfig(configHandler.GetMapsConfig())
{
    mapsConfig = configHandler.GetMapsConfig();
    
    for (int row = 0; row < mapsConfig.rows; row++)
     {
         for (int column = 0; column < mapsConfig.columns; column++)
         {
             const char* texturePath{ GetTexturePathByID(mapsConfig.layout[row][column]) };
             Vector2 tilePosition{ static_cast<float>(column), static_cast<float>(row) };
             Vector2 tileSize{ tileConfig.sizeX, tileConfig.sizeY };
             
             tileMap.emplace_back(renderer, texturePath, configHandler);
             tileMap.back().SetTileSize(tileSize);
             tileMap.back().SetTilePosition(tilePosition);
         }
     }
}

Map::~Map()
{
}

void Map::DrawMap()
{
    for (Tile& tile : tileMap)
    {
        tile.Render();
    }
}

const char* Map::GetTexturePathByID(const int i) const
{
    if (i == 0) return floorTexturePath;
    if (i == 1) return wallTexturePath;

    return defaultTexturePath;
}
