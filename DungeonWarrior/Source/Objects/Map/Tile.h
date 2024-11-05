#pragma once
#include "../../Components/Collision/BoxCollider.h"
#include "../../Components/Sprite/Sprite.h"
#include "../../Components/Transform/Transform.h"
#include "../../Utils/ConfigHandler.h"

class Tile
{
public:
    Tile(SDL_Renderer& renderer, const char* texturePath, std::string& tag);
    
    void Render() const;
    void Update();
    void Destroy();
    
    void SetTilePosition(const Vector2& newPosition) const;
    void SetTileSize(const Vector2& newSize) const;
    
    BoxCollider& GetCollider() const;

private:
    std::shared_ptr<Transform> m_Transform;
    std::shared_ptr<Sprite> m_Sprite;
    std::unique_ptr<BoxCollider> m_Collider;
};
