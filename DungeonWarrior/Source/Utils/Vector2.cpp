#include "Vector2.h"

#include <valarray>

Vector2::Vector2(float x, float y)
    :m_X(x), m_Y(y)
{
}

float Vector2::Magnitude() const
{
    return std::sqrtf((m_X * m_X) + (m_Y * m_Y));
}

Vector2 Vector2::Normalized() const
{
    float magnitude = Magnitude();
    if (magnitude == 0.0f) return Vector2{};

    return Vector2{m_X / magnitude, m_Y / magnitude};
}
