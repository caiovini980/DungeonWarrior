#include "BoxCollider.h"

// TODO 
BoxCollider::BoxCollider(Transform& entityTransform, std::string& tag)
    : transform(&entityTransform), collider(), tag(std::make_unique<std::string>(tag))
{
}

void BoxCollider::UpdateCollider()
{
    const Vector2 size = transform->GetSize();
    const Vector2 position = transform->GetPosition();

    collider.x = static_cast<int>(position.x);
    collider.y = static_cast<int>(position.y);
    collider.w = static_cast<int>(size.x);
    collider.h = static_cast<int>(size.y);
}

const SDL_Rect& BoxCollider::GetCollider() const
{
    return collider;
}

const std::string& BoxCollider::GetTag() const
{
    return *tag;
}
