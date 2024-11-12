#include "BoxCollider.h"

#include "../../Core/GameObject.h"
#include "../Transform/Transform.h"

void BoxCollider::SetupCollider(CollisionTypes collisionType)
{
    SetCollisionType(collisionType);
    GetTransform()->SetPosition(GetOwner()->GetTransform()->GetPosition());
}

void BoxCollider::Update()
{
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

const CollisionTypes& BoxCollider::GetCollisionType() const
{
    return Collider::GetCollisionType();
}
