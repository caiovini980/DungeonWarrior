#pragma once
#include <memory>

#include "Engine/GameObject.h"
#include "Engine/Components/Collision/CollisionTags.h"

class Vector2;
class BoxCollider;
class Sprite;
class Transform;
class CollisionManager;
struct SDL_Renderer;

class Tile : public GameObject
{
public:
    Tile() = default;
    ~Tile() override = default;
    
    void SetupTile(const char* texturePath, CollisionTypes collisionType);
    
    void SetTilePosition(const Vector2& newPosition) ;
    void SetTileSize(const Vector2& newSize) ;
    
    BoxCollider& GetCollider() const;

private:
    void Update() override;
    
    std::weak_ptr<Sprite> m_Sprite;
    std::weak_ptr<BoxCollider> m_Collider;
};
