#pragma once
#include <vector>
#include <string>

#include "../Core/GameObject.h"
#include "../Utils/ConfigHandler.h"

class CollisionManager;
class ConfigHandler;
class Tile;
struct SDL_Renderer;

class Map : public GameObject
{
public:
    Map();
    ~Map() override = default;

    void SetupMap(const MapsConfig& mapConfig, const TileConfig& tileConfig);

    std::vector<Tile*>& GetMapTiles();

private:
    const std::string& GetTexturePathByID(int i) const;

    void Update() override;
    
    std::vector<Tile*> m_Tiles;

    std::string m_FloorTexturePath {"Assets/Sprites/floor.png"};
    std::string m_WallTexturePath {"Assets/Sprites/wall.png"};
};
