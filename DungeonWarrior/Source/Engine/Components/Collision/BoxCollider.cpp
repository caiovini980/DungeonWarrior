#include "BoxCollider.h"

#include "../Transform/Transform.h"
#include "Engine/EngineManager.h"

BoxCollider::BoxCollider() : Collider(E_ColliderShape::Box)
{
}

void BoxCollider::SetupCollider(CollisionTags collisionTag)
{
    SetCollisionTag(collisionTag);
    EngineManager::GetInstance().RegisterCollider(weak_from_this());
}

void BoxCollider::Update()
{
    Collider::Update();
    
    const Vector2 size = GetTransform()->GetSize();
    const Vector2 position = GetTransform()->GetPosition();

    m_Collider.x = static_cast<int>(position.m_X);
    m_Collider.y = static_cast<int>(position.m_Y);
    m_Collider.w = static_cast<int>(size.m_X);
    m_Collider.h = static_cast<int>(size.m_Y);
}

const SDL_Rect& BoxCollider::GetCollider() const
{
    return m_Collider;
}
