#include "Map.h"

Map::Map(SDL_Renderer& renderer, ConfigHandler& configHandler)
    : tileConfig(&configHandler.GetTileConfig()), mapsConfig(&configHandler.GetMapsConfig())
{
    *mapsConfig = configHandler.GetMapsConfig();
    
    for (int row = 0; row < mapsConfig->rows; row++)
     {
         for (int column = 0; column < mapsConfig->columns; column++)
         {
             const char* texturePath{ GetTexturePathByID(mapsConfig->layout[row][column]) };
             Vector2 tilePosition{ static_cast<float>(column), static_cast<float>(row) };
             Vector2 tileSize{ tileConfig->sizeX, tileConfig->sizeY };

             if (texturePath == wallTexturePath)
             {
                 // TODO change the way we get this tag, maybe add it to some global file
                 std::string wallTag{"wall"};
                 tileMap.emplace_back(renderer, texturePath, wallTag);
             }
             else
             {
                 // TODO change the way we get this tag, maybe add it to some global file
                 std::string floorTag{"floor"};
                 tileMap.emplace_back(renderer, texturePath, floorTag);
             }
             
             tileMap.back().SetTileSize(tileSize);
             tileMap.back().SetTilePosition(tilePosition);
         }
     }

    // Update tile position
    for (auto& tile : tileMap)
    {
        tile.GetCollider().UpdateCollider();
    }
}

void Map::DrawMap()
{
    for (Tile& tile : tileMap)
    {
        tile.Render();
    }
}

std::vector<Tile>& Map::GetMapTiles()
{
    return tileMap;
}

const char* Map::GetTexturePathByID(const int i) const
{
    if (i == 0) return floorTexturePath;
    if (i == 1) return wallTexturePath;

    return defaultTexturePath;
}
