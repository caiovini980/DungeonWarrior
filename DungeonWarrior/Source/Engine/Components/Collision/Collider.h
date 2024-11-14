#pragma once
#include <map>
#include <memory>
#include <SDL_rect.h>
#include <string>

#include "../Component.h"
#include "Core/Tags/CollisionTags.h"

class Transform;

enum class E_ColliderShape : uint8_t
{
    Box
};

class Collider : public Component
{
public:
    Collider(E_ColliderShape newShape);
    virtual ~Collider() override = default;
    
    CollisionTypes GetCollisionType() const { return m_CollisionType; }
    E_ColliderShape GetColliderShape() const { return m_Shape; } 

    void SetCollisionMapValue(CollisionTypes type, bool canCollide);
    bool GetCollisionMapValue(CollisionTypes type);
    
protected:
    virtual void SetupCollider(const CollisionTypes collisionType) = 0;
    virtual void Update() override;

    void SetCollisionType(const CollisionTypes newType) { m_CollisionType = newType; }
    
    Transform* GetTransform() const { return m_Transform.get(); }
    
private:
    std::shared_ptr<Transform> m_Transform;

    CollisionTypes m_CollisionType;
    const E_ColliderShape m_Shape;

    std::map<CollisionTypes, bool> m_CollisionMap{};
};
