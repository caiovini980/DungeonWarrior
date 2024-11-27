#pragma once

#include <memory>
#include <SDL_rect.h>
#include <string>

#include "Engine/Components/Component.h"
#include "Utils/Vector2.h"

class Transform : public Component
{
public:
    Transform();

    void SetPosition(float x, float y);
    void SetPosition(const Vector2& newPosition);

    void AddPosition(const Vector2& addedPosition);
    
    void SetScale(float x, float y);
    void SetScale(const Vector2& newScale);
    
    void SetDirection(float x, float y);
    void SetDirectionHorizontally(float x);
    void SetDirectionVertically(float y);

    const Vector2& GetPosition() const;
    const Vector2& GetSize() const;
    const Vector2& GetDirection() const;

    SDL_Rect* GetSDLRect();

    Vector2 GetPreviousPosition() const;

private:
    void LateUpdate() override;
    
    Vector2 m_Position;
    Vector2 m_Scale;
    Vector2 m_PreviousPosition;
    Vector2 m_Direction;

    SDL_Rect m_ResultRect;
    SDL_Rect m_SourceRect;
};
