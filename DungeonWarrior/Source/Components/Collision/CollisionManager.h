#pragma once
#include <SDL_rect.h>

#include "BoxCollider.h"

class CollisionManager
{
public:
    // AABB Collision
    static bool CheckCollision(const BoxCollider& colliderA, const BoxCollider& colliderB);
};
