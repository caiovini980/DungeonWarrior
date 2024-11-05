#include "CollisionManager.h"

bool CollisionManager::CheckCollision(const BoxCollider& colliderA, const BoxCollider& colliderB)
{
    SDL_Rect rectA = colliderA.GetCollider();
    SDL_Rect rectB = colliderB.GetCollider();
    
    return (
        rectA.x + rectA.w >= rectB.x &&
        rectA.y + rectA.h >= rectB.y &&
        rectB.x + rectB.w >= rectA.x &&
        rectB.y + rectB.h >= rectA.y
    );
}

template<typename T, typename = std::enable_if_t<std::is_base_of_v<Collider, T>>>
std::unique_ptr<T> CollisionManager::CreateCollider(Transform& entityTransform, std::string& tag)
{
    return std::make_unique<T>(entityTransform, tag);
}