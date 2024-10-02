#include "ConfigHandler.h"

ConfigHandler::ConfigHandler()
{
    LoadWindowConfigs();
    LoadPlayerConfigs();
    LoadTileConfigs();
}

ConfigHandler::~ConfigHandler()
{
}

JSON ConfigHandler::GetParsedJSON(const std::string& path)
{
    std::ifstream file(path);
    JSON parsedData;
    
    try
    {
        parsedData = JSON::parse(file);
    }
    catch (const JSON::parse_error& error)
    {
        std::cerr << "ERROR: " << error.id << "\n"
                  << "MESSAGE: " << error.what() << ".\n"
                  << "BYTE POSITION: " << error.byte << "\n";
    }
    
    return parsedData;
}

void ConfigHandler::LoadPlayerConfigs()
{
    JSON playerData = GetParsedJSON(PLAYER_CONFIG_PATH);

    // TODO maybe remove these strings?
    playerConfig.textureIndex = playerData["textureIndex"].get<const int>();
    playerConfig.speed = playerData["speed"].get<const float>();
    playerConfig.sizeX = playerData["size"]["x"].get<const float>();
    playerConfig.sizeY = playerData["size"]["y"].get<const float>();
}

void ConfigHandler::LoadTileConfigs()
{
    JSON tileData = GetParsedJSON(TILE_CONFIG_PATH);
        
    // TODO maybe remove these strings?
    tileConfig.sizeX = tileData["size"]["x"].get<const float>();
    tileConfig.sizeY = tileData["size"]["y"].get<const float>();
}

void ConfigHandler::LoadWindowConfigs()
{
    JSON windowData = GetParsedJSON(WINDOW_CONFIG_PATH);
        
    // TODO maybe remove these strings?
    windowConfig.width = windowData["width"].get<const int>();
    windowConfig.height = windowData["height"].get<const int>();
    windowConfig.title = windowData["title"].get<const std::string>();
    windowConfig.fullscreen = windowData["fullscreen"].get<const bool>();

    
}

PlayerConfig& ConfigHandler::GetPlayerConfig()
{
    return playerConfig;
}

MapsConfig& ConfigHandler::GetMapsConfig()
{
    return mapsConfig;
}

TileConfig& ConfigHandler::GetTileConfig()
{
    return tileConfig;
}

WindowConfig& ConfigHandler::GetWindowConfig()
{
    return windowConfig;
}
