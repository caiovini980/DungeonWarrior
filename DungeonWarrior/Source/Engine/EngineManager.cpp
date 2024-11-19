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

    for (auto colliderA : m_Colliders)
    {
        for (auto colliderB : m_Colliders)
        {
            SDL_Rect result {};
            
            if (CheckCollision(colliderA, colliderB, &result))
            {
                std::cout << "Is colliding!\n";
                // const std::shared_ptr<Transform> transform = colA->GetOwner()->GetTransform();
                // transform->SetPosition(transform->GetPreviousPosition());
            }
        }
    }

    for (auto& element : m_GameObjects)
    {
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

void EngineManager::RegisterCollider(Collider* collider)
{
    assert(collider, "Must register a valid collider.\n");
    m_Colliders.push_back(collider);
}

SDL_bool EngineManager::CheckCollision(Collider* colliderA, Collider* colliderB, SDL_Rect* result)
{
    if (colliderA->GetColliderShape() == E_ColliderShape::Box &&
        colliderB->GetColliderShape() == E_ColliderShape::Box)
    {
        if (colliderA->GetCollisionMapValue(colliderB->GetCollisionType()) &&
            colliderB->GetCollisionMapValue(colliderA->GetCollisionType()))
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
