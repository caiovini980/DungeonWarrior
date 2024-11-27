#include "EngineManager.h"

#include <assert.h>
#include <iostream>

#include "Components/Transform/Transform.h"
#include "Engine/GameObject.h"

std::shared_ptr<EngineManager> EngineManager::m_Instance;

EngineManager& EngineManager::GetInstance()
{
    if (!m_Instance)
    {
        m_Instance = std::make_shared<EngineManager>();
    }
    
    return *m_Instance;
}

void EngineManager::Update()
{
    for (auto& element : m_GameObjects)
    {
        element->UpdateComponents();
        element->Update();
    }

    for (auto& colliderA : m_Colliders)
    {
        if (colliderA.expired()) { continue; }
        
        for (auto& colliderB : m_Colliders)
        {
            if (colliderB.expired()) { continue; }
            
            SDL_Rect result {};
            
            if (CheckCollision(colliderA.lock().get(), colliderB.lock().get(), &result))
            {
                // std::cout << "Is colliding!\n";

                // apply collision just to player
                // get just the player transform
                std::shared_ptr<Transform> transform;
                if (colliderA.lock()->GetCollisionTag() == CollisionTags::PLAYER)
                {
                    transform = colliderA.lock()->GetOwner()->GetTransform();
                }
                else if (colliderB.lock()->GetCollisionTag() == CollisionTags::PLAYER)
                {
                    transform = colliderB.lock()->GetOwner()->GetTransform();
                }

                // check horizontal movement
                // the new position will be derived from the object's current position
                Vector2 newPosition = transform->GetPosition();
                float collisionOffset = 4.0f;
                if (transform->GetDirection().m_X > 0)
                {
                    // go left
                    newPosition.m_X = transform->GetPosition().m_X - (static_cast<float>(result.w) + collisionOffset);
                }
                if (transform->GetDirection().m_X < 0)
                {
                    // go right
                    newPosition.m_X = transform->GetPosition().m_X + (static_cast<float>(result.w) + collisionOffset);
                }

                // check vertical movement
                if (transform->GetDirection().m_Y > 0)
                {
                    // go up
                    newPosition.m_Y = transform->GetPosition().m_Y - (static_cast<float>(result.h) + collisionOffset);
                }
                if (transform->GetDirection().m_Y < 0)
                {
                    // go down
                    newPosition.m_Y = transform->GetPosition().m_Y + (static_cast<float>(result.h) + collisionOffset);
                }
                
                transform->SetPosition(newPosition);
            }
        }
    }

    for (auto& element : m_GameObjects)
    {
        element->LateUpdate();
        element->LateUpdateComponents();
    }
}

void EngineManager::Render() const
{
    for (auto& element : m_GameObjects)
    {
        element->Render();
    }
}

void EngineManager::Destroy(GameObject* gameObject)
{
    auto it = std::find_if(
        m_GameObjects.begin(), m_GameObjects.end(),
            [gameObject](const std::shared_ptr<GameObject>& item)
            {
                return item.get() == gameObject;
            });

    if (it != m_GameObjects.end())
    {
        m_GameObjects.erase(it);
    }
}

void EngineManager::RegisterCollider(const std::weak_ptr<Collider>& collider)
{
    assert(collider.lock(), "Must register a valid collider.\n");
    m_Colliders.push_back(collider);
}

SDL_bool EngineManager::CheckCollision(Collider* colliderA, Collider* colliderB, SDL_Rect* result)
{
    if (colliderA->GetColliderShape() == E_ColliderShape::Box &&
        colliderB->GetColliderShape() == E_ColliderShape::Box)
    {
        if (colliderA->GetCollisionMapValue(colliderB->GetCollisionTag()) &&
            colliderB->GetCollisionMapValue(colliderA->GetCollisionTag()))
        {
            return CheckCollision(dynamic_cast<BoxCollider*>(colliderA), dynamic_cast<BoxCollider*>(colliderB), result);
        }
    }

    return SDL_FALSE;
}

SDL_bool EngineManager::CheckCollision(BoxCollider* colliderA, BoxCollider* colliderB, SDL_Rect* result)
{
    // if both are BoxCollider, do AABB
    SDL_Rect rectA = colliderA->GetCollider();
    SDL_Rect rectB = colliderB->GetCollider();
    
    return (
        SDL_IntersectRect(&rectA, &rectB, result)
    );
}
