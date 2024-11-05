#pragma once

#include <memory>
#include <SDL_rect.h>
#include <string>

#include "../../Utils/Vector2.h"

class Transform
{
public:
    Transform();

    void SetPosition(float x, float y);
    void SetPosition(const Vector2& newPosition);

    void AddPosition(const Vector2& addedPosition);
    
    void SetScale(float x, float y);
    
    Vector2& GetPosition() const;
    Vector2& GetSize() const;

    SDL_Rect* GetResultTransform();

private:
    std::unique_ptr<Vector2> m_Position;
    std::unique_ptr<Vector2> m_Scale;
    // rotation?

    SDL_Rect m_ResultRect;
    SDL_Rect m_SourceRect;
};
