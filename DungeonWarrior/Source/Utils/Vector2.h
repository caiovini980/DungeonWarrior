#pragma once

class Vector2
{
public:
    Vector2(float x = 0.0f, float y = 0.0f);
    
    float Magnitude() const;
    Vector2 Normalized() const;
    
    float x{0.0f};
    float y{0.0f};

    // overloads
    Vector2 operator* (float scalar) const
    {
        return Vector2{x * scalar, y * scalar};
    }

    Vector2& operator*= (float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2 operator- (const Vector2& other) const
    {
        return Vector2{x - other.x, y - other.y};
    }

    Vector2 operator+ (const Vector2& other) const
    {
        return Vector2{x + other.x, y + other.y};
    }
};
