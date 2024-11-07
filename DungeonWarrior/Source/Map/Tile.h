#pragma once
#include <memory>
#include "../Core/Tags/CollisionTags.h"

class Vector2;
class BoxCollider;
class Sprite;
class Transform;
class CollisionManager;
struct SDL_Renderer;

class Tile
{
public:
    Tile(SDL_Renderer& renderer, const char* texturePath, CollisionManager& collisionManager, CollisionTypes collisionType = CollisionTypes::FLOOR);
    ~Tile() = default;
    
    void Render();
    
    void SetTilePosition(const Vector2& newPosition) const;
    void SetTileSize(const Vector2& newSize) const;
    
    BoxCollider& GetCollider() const;

private:
    std::shared_ptr<Transform> m_Transform;
    std::shared_ptr<Sprite> m_Sprite;
    std::shared_ptr<BoxCollider> m_Collider;
};
