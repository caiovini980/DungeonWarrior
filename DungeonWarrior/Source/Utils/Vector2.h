#pragma once

class Vector2
{
public:
    Vector2(float x = 0.0f, float y = 0.0f);
    
    float Magnitude() const;
    Vector2 Normalized() const;
    
    float m_X{0.0f};
    float m_Y{0.0f};

    // overloads
    Vector2 operator* (float scalar) const
    {
        return Vector2{m_X * scalar, m_Y * scalar};
    }

    Vector2& operator*= (float scalar)
    {
        m_X *= scalar;
        m_Y *= scalar;
        return *this;
    }

    Vector2 operator- (const Vector2& other) const
    {
        return Vector2{m_X - other.m_X, m_Y - other.m_Y};
    }

    Vector2 operator+ (const Vector2& other) const
    {
        return Vector2{m_X + other.m_X, m_Y + other.m_Y};
    }
};
