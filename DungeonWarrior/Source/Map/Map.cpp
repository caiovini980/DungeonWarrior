#include "Map.h"

#include "../Utils/Vector2.h"
#include "../Core/Tags/CollisionTags.h"
#include "../Utils/ConfigHandler.h"
#include "Tile.h"

Map::Map(SDL_Renderer& renderer, CollisionManager& collisionManager, ConfigHandler& configHandler)
    : m_TileConfig(&configHandler.GetTileConfig()), m_MapsConfig(&configHandler.GetMapsConfig())
{
    for (int row = 0; row < m_MapsConfig->rows; row++)
     {
         for (int column = 0; column < m_MapsConfig->columns; column++)
         {
             std::string texturePath{ GetTexturePathByID(m_MapsConfig->layout[row][column]) };
             Vector2 tilePosition{ static_cast<float>(column), static_cast<float>(row) };
             Vector2 tileSize{ m_TileConfig->sizeX, m_TileConfig->sizeY };

             // TODO resolve this issue
             if (texturePath == m_WallTexturePath)
             {
                 m_Tiles.emplace_back(std::make_shared<Tile>(renderer, texturePath.c_str(), collisionManager, CollisionTypes::WALL));
             }
             else
             {
                 m_Tiles.emplace_back(std::make_shared<Tile>(renderer, texturePath.c_str(), collisionManager, CollisionTypes::FLOOR));
             }
             
             m_Tiles.back()->SetTileSize(tileSize);
             m_Tiles.back()->SetTilePosition(tilePosition);
         }
     }

    // Update tile position
    for (auto& tile : m_Tiles)
    {
        // tile.GetCollider().UpdateCollider();
    }
}

void Map::DrawMap() const
{
    for (const std::shared_ptr<Tile>& tile : m_Tiles)
    {
        tile->Render();
    }
}

std::vector<std::shared_ptr<Tile>>& Map::GetMapTiles()
{
    return m_Tiles;
}

const std::string& Map::GetTexturePathByID(const int i) const
{
    if (i == 0) return m_FloorTexturePath;
    if (i == 1) return m_WallTexturePath;

    return m_FloorTexturePath;
}
