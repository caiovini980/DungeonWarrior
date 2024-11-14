#include "Map.h"

#include "Utils/Vector2.h"
#include "Utils/ConfigHandler.h"
#include "Tile.h"
#include "Engine/EngineManager.h"

Map::Map() {}

void Map::SetupMap(const MapsConfig& mapConfig, const TileConfig& tileConfig)
{
    for (int row = 0; row < mapConfig.rows; row++)
    {
        for (int column = 0; column < mapConfig.columns; column++)
        {
            std::string texturePath{ GetTexturePathByID(mapConfig.layout[row][column]) };
            Vector2 tilePosition{ static_cast<float>(column), static_cast<float>(row) };
            Vector2 tileSize{ tileConfig.sizeX, tileConfig.sizeY };

            Tile* tile = &EngineManager::GetInstance().SpawnGameObject<Tile>();

            if (texturePath == m_FloorTexturePath)
            {
                tile->SetupTile(texturePath.c_str(), CollisionTypes::FLOOR);
            }
            else
            {
                tile->SetupTile(texturePath.c_str(), CollisionTypes::WALL);
            }
            
            m_Tiles.push_back(tile);
            
            m_Tiles.back()->SetTileSize(tileSize);
            m_Tiles.back()->SetTilePosition(tilePosition);
        }
    }
}

std::vector<Tile*>& Map::GetMapTiles()
{
    return m_Tiles;
}

const std::string& Map::GetTexturePathByID(const int i) const
{
    if (i == 0) return m_FloorTexturePath;
    if (i == 1) return m_WallTexturePath;

    return m_FloorTexturePath;
}

void Map::Update()
{
    
}
