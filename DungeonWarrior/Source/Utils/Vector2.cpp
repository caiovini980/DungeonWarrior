#include "Vector2.h"

#include <valarray>

Vector2::Vector2(float x, float y)
    :x(x), y(y)
{
}

float Vector2::Magnitude() const
{
    return std::sqrtf((x * x) + (y * y));
}

Vector2 Vector2::Normalized() const
{
    float magnitude = Magnitude();
    if (magnitude == 0.0f) return Vector2{};

    return Vector2{x / magnitude, y / magnitude};
}
