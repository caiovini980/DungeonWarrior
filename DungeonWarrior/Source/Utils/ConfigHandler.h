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

    static JSON GetParsedJSON(const std::string& path);
    
    PlayerConfig& GetPlayerConfig();
    MapsConfig& GetMapsConfig();
    TileConfig& GetTileConfig();
    WindowConfig& GetWindowConfig();

private:
    const std::unique_ptr<std::string> PLAYER_CONFIG_PATH{ std::make_unique<std::string>("./Settings/PlayerConfig.json") };
    const std::unique_ptr<std::string> TILE_CONFIG_PATH{ std::make_unique<std::string>("./Settings/TileConfig.json") };
    const std::unique_ptr<std::string> WINDOW_CONFIG_PATH{ std::make_unique<std::string>("./Settings/WindowConfig.json") };
    const std::unique_ptr<std::string> MAP_CONFIG_PATH{ std::make_unique<std::string>("./Settings/MapsConfig.json") };
    
    void LoadPlayerConfigs();
    void LoadTileConfigs();
    void LoadWindowConfigs();
    void LoadMapConfigs(int mapId);

    PlayerConfig m_PlayerConfig;
    MapsConfig m_MapsConfig;
    TileConfig m_TileConfig;
    WindowConfig m_WindowConfig;
};

