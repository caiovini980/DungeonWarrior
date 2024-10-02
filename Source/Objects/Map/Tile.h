#pragma once
#include "../../Components/Sprite/Sprite.h"
#include "../../Components/Transform/Transform.h"
#include "../../Utils/ConfigHandler.h"

class Tile
{
public:
    Tile(SDL_Renderer& renderer, const char* texturePath, ConfigHandler& configHandler);
    
    ~Tile();
    void Render() const;
    void Update();
    void Destroy();
    
    void SetTilePosition(const Vector2& newPosition) const;
    void SetTileSize(const Vector2& newSize) const;

private:
    std::shared_ptr<Transform> transform;
    std::shared_ptr<Sprite> sprite;
};
