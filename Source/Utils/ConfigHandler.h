#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include "../../Libraries/nlohmann/json.hpp"
using JSON = nlohmann::json;

// Structs
struct PlayerConfig
{
    int textureIndex;

    float speed;
    float sizeX;
    float sizeY;
};

struct WindowConfig
{
    int width;
    int height;
    
    bool fullscreen;
    
    std::string title;
};

struct MapsConfig
{
    int rows;
    int columns;
    std::vector<std::vector<int>> layout;
};

struct TileConfig
{
    float sizeX;
    float sizeY;
};

// Class
class ConfigHandler
{
public:
    ConfigHandler();
    ~ConfigHandler();

    JSON GetParsedJSON(const std::string& path);
    
    PlayerConfig& GetPlayerConfig();
    MapsConfig& GetMapsConfig();
    TileConfig& GetTileConfig();
    WindowConfig& GetWindowConfig();

private:
    const std::string PLAYER_CONFIG_PATH{ "./Settings/PlayerConfig.json" };
    const std::string TILE_CONFIG_PATH{ "./Settings/TileConfig.json" };
    const std::string WINDOW_CONFIG_PATH{ "./Settings/WindowConfig.json" };
    const std::string MAP_CONFIG_PATH{ "./Settings/MapsConfig.json" };
    
    void LoadPlayerConfigs();
    void LoadTileConfigs();
    void LoadWindowConfigs();
    void LoadMapConfigs(int mapId);

    PlayerConfig playerConfig;
    MapsConfig mapsConfig;
    TileConfig tileConfig;
    WindowConfig windowConfig;
};

