#pragma once
#include <memory>
#include <string>

#include "../../Core/Tags/CollisionTags.h"
#include "../Transform/Transform.h"

class Collider
{
    virtual const CollisionTypes& GetCollisionType() const = 0;
    
public:
    Collider(const std::shared_ptr<Transform>& transform, CollisionTypes collisionType)
        : m_Transform(transform), m_CollisionType(collisionType){}
    virtual ~Collider() = default;
    
    std::shared_ptr<Transform> m_Transform;
    CollisionTypes m_CollisionType;
};
