#pragma once

#include "BoxCollider.h"

class CollisionManager 
{
public:
    // AABB Collision
    bool CheckCollision(const BoxCollider& colliderA, const BoxCollider& colliderB);
};
