#include "Map.h"

Map::Map(SDL_Renderer& renderer, ConfigHandler& configHandler)
    : m_TileConfig(&configHandler.GetTileConfig()), m_MapsConfig(&configHandler.GetMapsConfig())
{
    *m_MapsConfig = configHandler.GetMapsConfig();
    
    for (int row = 0; row < m_MapsConfig->rows; row++)
     {
         for (int column = 0; column < m_MapsConfig->columns; column++)
         {
             std::string texturePath{ GetTexturePathByID(m_MapsConfig->layout[row][column]) };
             Vector2 tilePosition{ static_cast<float>(column), static_cast<float>(row) };
             Vector2 tileSize{ m_TileConfig->sizeX, m_TileConfig->sizeY };

             if (texturePath == *m_WallTexturePath)
             {
                 // TODO change the way we get this tag, maybe add it to some global file
                 std::string wallTag{"wall"};
                 m_Tiles.emplace_back(renderer, texturePath.c_str(), wallTag);
             }
             else
             {
                 // TODO change the way we get this tag, maybe add it to some global file
                 std::string floorTag{"floor"};
                 m_Tiles.emplace_back(renderer, texturePath.c_str(), floorTag);
             }
             
             m_Tiles.back().SetTileSize(tileSize);
             m_Tiles.back().SetTilePosition(tilePosition);
         }
     }

    // Update tile position
    for (auto& tile : m_Tiles)
    {
        tile.GetCollider().UpdateCollider();
    }
}

void Map::DrawMap()
{
    for (Tile& tile : m_Tiles)
    {
        tile.Render();
    }
}

std::vector<Tile>& Map::GetMapTiles()
{
    return m_Tiles;
}

const std::string& Map::GetTexturePathByID(const int i) const
{
    if (i == 0) return *m_FloorTexturePath;
    if (i == 1) return *m_WallTexturePath;

    return *m_FloorTexturePath;
}
