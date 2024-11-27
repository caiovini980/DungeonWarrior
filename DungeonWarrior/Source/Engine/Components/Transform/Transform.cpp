#include "Transform.h"

#include <memory>

Transform::Transform()
    : m_Position(0, 0), m_Scale(32, 32)
{
    
}

void Transform::LateUpdate()
{
}

void Transform::SetPosition(float x, float y)
{
    m_PreviousPosition = m_Position;
    
    m_ResultRect.x = static_cast<int>(x);
    m_ResultRect.y = static_cast<int>(y);

    m_Position.m_X = x;
    m_Position.m_Y = y;
}

void Transform::SetPosition(const Vector2& newPosition)
{
    SetPosition(newPosition.m_X, newPosition.m_Y);
}

void Transform::AddPosition(const Vector2& addedPosition)
{
    SetPosition(m_Position.m_X + addedPosition.m_X, m_Position.m_Y + addedPosition.m_Y);
}

void Transform::SetScale(float x, float y)
{
    m_ResultRect.w = static_cast<int>(x);
    m_ResultRect.h = static_cast<int>(y);

    m_Scale.m_X = x;
    m_Scale.m_Y = y;
}

void Transform::SetScale(const Vector2& newScale)
{
    SetScale(newScale.m_X, newScale.m_Y);
}

void Transform::SetDirection(float x, float y)
{
    Vector2 newDirection{x, y};
    m_Direction = newDirection;
}

void Transform::SetDirectionHorizontally(float x)
{
    m_Direction.m_X = x;
}

void Transform::SetDirectionVertically(float y)
{
    m_Direction.m_Y = y;
}

const Vector2& Transform::GetPosition() const
{
    return m_Position;
}

const Vector2& Transform::GetSize() const
{
    return m_Scale;
}

const Vector2& Transform::GetDirection() const
{
    return m_Direction;
}

SDL_Rect* Transform::GetSDLRect()
{
    return &m_ResultRect;
}

Vector2 Transform::GetPreviousPosition() const
{
    return m_PreviousPosition;
}
