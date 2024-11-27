#pragma once
#include <map>
#include <memory>
#include <SDL_rect.h>
#include <string>

#include "../Component.h"
#include "CollisionTags.h"

class Transform;

enum class E_ColliderShape : uint8_t
{
    Box
};

class Collider : public Component, public std::enable_shared_from_this<Collider>
{
public:
    Collider(E_ColliderShape newShape);
    ~Collider() override = default;
    
    CollisionTags GetCollisionTag() const { return m_CollisionTag; }
    E_ColliderShape GetColliderShape() const { return m_Shape; } 

    void SetCollisionMapValue(const CollisionTags tag, bool canCollide);
    bool GetCollisionMapValue(CollisionTags tag);
    
protected:
    virtual void SetupCollider(const CollisionTags collisionTag) = 0;
    virtual void Update() override;

    void SetCollisionTag(const CollisionTags newTag) { m_CollisionTag = newTag; }
    
    Transform* GetTransform() const { return m_Transform.get(); }
    
private:
    std::shared_ptr<Transform> m_Transform;

    CollisionTags m_CollisionTag;
    const E_ColliderShape m_Shape;

    std::map<CollisionTags, bool> m_CollisionMap{};
};
