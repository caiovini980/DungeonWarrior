#include "BoxCollider.h"

// TODO 
BoxCollider::BoxCollider(Transform& entityTransform, std::string& tag)
    : m_Transform(&entityTransform), m_Collider(), m_Tag(std::make_unique<std::string>(tag))
{
}

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

const std::string& BoxCollider::GetTag() const
{
    return *m_Tag;
}
