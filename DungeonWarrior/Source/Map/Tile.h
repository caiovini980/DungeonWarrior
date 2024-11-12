#pragma once
#include <memory>

#include "../Core/GameObject.h"
#include "../Core/Tags/CollisionTags.h"

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
    
    // void Render();
    void SetupTile(const char* texturePath, CollisionTypes collisionType);
    
    void SetTilePosition(const Vector2& newPosition) const;
    void SetTileSize(const Vector2& newSize) const;
    
    BoxCollider& GetCollider() const;

private:
    void Update() override;
    
    Sprite* m_Sprite;
    BoxCollider* m_Collider;
    // std::shared_ptr<BoxCollider> m_Collider;
};
