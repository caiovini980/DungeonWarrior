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
    void SetScale(const Vector2& newScale);

    const Vector2& GetPosition() const;
    const Vector2& GetSize() const;

    SDL_Rect* GetSDLRect();

private:
    Vector2 m_Position;
    Vector2 m_Scale;
    Vector2 m_PreviousValidPosition;

    SDL_Rect m_ResultRect;
    SDL_Rect m_SourceRect;
};
