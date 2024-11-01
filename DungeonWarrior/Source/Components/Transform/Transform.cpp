#include "Transform.h"

#include <memory>

Transform::Transform()
    : position(std::make_unique<Vector2>(0, 0)), scale(std::make_unique<Vector2>(32, 32))
{
}

Transform::~Transform()
{
}

void Transform::SetPosition(float x, float y)
{
    resultRect.x = static_cast<int>(x);
    resultRect.y = static_cast<int>(y);

    position->x = x;
    position->y = y;
}

void Transform::SetPosition(const Vector2& newPosition)
{
    SetPosition(newPosition.x, newPosition.y);
}

void Transform::AddPosition(const Vector2& addedPosition)
{
    SetPosition(position->x + addedPosition.x, position->y + addedPosition.y);
}

void Transform::SetScale(float x, float y)
{
    resultRect.w = static_cast<int>(x);
    resultRect.h = static_cast<int>(y);

    scale->x = x;
    scale->y = y;
}

Vector2& Transform::GetPosition() const
{
    return *position;
}

Vector2& Transform::GetScale() const
{
    return *scale;
}

SDL_Rect* Transform::GetResultTransform()
{
    return &resultRect;
}
