#include "ConfigHandler.h"

ConfigHandler::ConfigHandler()
{
    LoadWindowConfigs();
    LoadPlayerConfigs();
    LoadTileConfigs();
    LoadMapConfigs(0);
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
    JSON playerData = GetParsedJSON(*PLAYER_CONFIG_PATH);

    // TODO maybe remove these strings?
    m_PlayerConfig.textureIndex = playerData["textureIndex"].get<const int>();
    m_PlayerConfig.speed = playerData["speed"].get<const float>();
    m_PlayerConfig.sizeX = playerData["size"]["x"].get<const float>();
    m_PlayerConfig.sizeY = playerData["size"]["y"].get<const float>();
}

void ConfigHandler::LoadTileConfigs()
{
    JSON tileData = GetParsedJSON(*TILE_CONFIG_PATH);
        
    // TODO maybe remove these strings?
    m_TileConfig.sizeX = tileData["size"]["x"].get<const float>();
    m_TileConfig.sizeY = tileData["size"]["y"].get<const float>();
}

void ConfigHandler::LoadWindowConfigs()
{
    JSON windowData = GetParsedJSON(*WINDOW_CONFIG_PATH);
        
    // TODO maybe remove these strings?
    m_WindowConfig.width = windowData["width"].get<const int>();
    m_WindowConfig.height = windowData["height"].get<const int>();
    m_WindowConfig.title = windowData["title"].get<const std::string>();
    m_WindowConfig.fullscreen = windowData["fullscreen"].get<const bool>();
}

void ConfigHandler::LoadMapConfigs(int mapId)
{
    JSON mapData = GetParsedJSON(*MAP_CONFIG_PATH);
    auto requestedMapInfo = mapData["maps"][mapId];
        
    // TODO maybe remove these strings?
    m_MapsConfig.rows = requestedMapInfo["rows"].get<const int>();
    m_MapsConfig.columns = requestedMapInfo["columns"].get<const int>();
    m_MapsConfig.layout = requestedMapInfo["layout"].get<const std::vector<std::vector<int>>>();
}

PlayerConfig& ConfigHandler::GetPlayerConfig()
{
    return m_PlayerConfig;
}

MapsConfig& ConfigHandler::GetMapsConfig()
{
    return m_MapsConfig;
}

TileConfig& ConfigHandler::GetTileConfig()
{
    return m_TileConfig;
}

WindowConfig& ConfigHandler::GetWindowConfig()
{
    return m_WindowConfig;
}
