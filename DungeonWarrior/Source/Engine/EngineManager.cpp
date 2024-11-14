#include "EngineManager.h"

#include <assert.h>
#include <iostream>

#include "Engine/GameObject.h"

EngineManager* EngineManager::m_Instance;

EngineManager& EngineManager::GetInstance()
{
    if (!m_Instance)
    {
        m_Instance = new EngineManager();
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

    for (Collider* colliderA : m_Colliders)
    {
        for (Collider* colliderB : m_Colliders)
        {
            if (colliderA == colliderB) continue;
            
            if (CheckCollision(colliderA, colliderB))
            {
                std::cout << "Is colliding!\n";
                
            }
        }
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

bool EngineManager::CheckCollision(Collider* colliderA, Collider* colliderB)
{
    if (colliderA->GetColliderShape() == E_ColliderShape::Box &&
        colliderB->GetColliderShape() == E_ColliderShape::Box)
    {
        if (colliderA->GetCollisionMapValue(colliderB->GetCollisionType()) &&
            colliderB->GetCollisionMapValue(colliderA->GetCollisionType()))
        {
            return CheckCollision(dynamic_cast<BoxCollider*>(colliderA), dynamic_cast<BoxCollider*>(colliderB));
        }
    }

    return false;
}

bool EngineManager::CheckCollision(BoxCollider* colliderA, BoxCollider* colliderB)
{
    // if both are BoxCollider, do AABB
    SDL_Rect rectA = colliderA->GetCollider();
    SDL_Rect rectB = colliderB->GetCollider();
        
    return (
        rectA.x + rectA.w >= rectB.x &&
        rectA.y + rectA.h >= rectB.y &&
        rectB.x + rectB.w >= rectA.x &&
        rectB.y + rectB.h >= rectA.y
    );
}
