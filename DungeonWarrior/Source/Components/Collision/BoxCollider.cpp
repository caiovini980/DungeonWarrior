#include "BoxCollider.h"

BoxCollider::BoxCollider(const std::shared_ptr<Transform>& entityTransform, CollisionTypes collisionType)
    : Collider(entityTransform, collisionType)
{}

void BoxCollider::UpdateCollider()
{
    const Vector2 size = m_Transform->GetSize();
    const Vector2 position = m_Transform->GetPosition();

    m_Collider.x = static_cast<int>(position.m_X);
    m_Collider.y = static_cast<int>(position.m_Y);
    m_Collider.w = static_cast<int>(size.m_X);
    m_Collider.h = static_cast<int>(size.m_Y);
}

const SDL_Rect& BoxCollider::GetCollider() const
{
    return m_Collider;
}

const CollisionTypes& BoxCollider::GetCollisionType() const
{
    return m_CollisionType;
}
