#pragma once
#include <memory>
#include <string>

#include "../Component.h"
#include "../../Core/Tags/CollisionTags.h"

class Transform;

class Collider : public Component
{
public:
    Collider();
    virtual ~Collider() override = default;

protected:
    virtual void SetupCollider(const CollisionTypes collisionType) = 0;

    Transform* GetTransform() const { return m_Transform.get(); }

    void SetCollisionType(const CollisionTypes newType) { m_CollisionType = newType; }
    virtual const CollisionTypes& GetCollisionType() const { return m_CollisionType; }
    
    virtual void Update() override;

private:
    std::shared_ptr<Transform> m_Transform;
    CollisionTypes m_CollisionType;
};
