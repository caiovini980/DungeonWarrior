#pragma once
#include <SDL_rect.h>

#include "BoxCollider.h"

class CollisionManager 
{
public:
    // AABB Collision
    bool CheckCollision(const BoxCollider& colliderA, const BoxCollider& colliderB);

    template<typename T, typename = std::enable_if_t<std::is_base_of_v<Collider, T>>>
    std::unique_ptr<T> CreateCollider(Transform& entityTransform, CollisionTypes collisionType);
};
