#pragma once

class Vector2
{
public:
    Vector2(float x = 0.0f, float y = 0.0f);
    ~Vector2();
    
    float Magnitude() const;
    Vector2 Normalized() const;
    
    float x{0.0f};
    float y{0.0f};

    // overload
    // Multiply
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
};
