#pragma once

#include <memory>
#include <SDL_rect.h>

#include "../../Utils/Vector2.h"

class Transform
{
public:
    Transform();
    ~Transform();

    void SetPosition(float x, float y);
    void SetPosition(const Vector2& newPosition);

    void AddPosition(const Vector2& addedPosition);
    
    void SetScale(float x, float y);
    
    Vector2& GetPosition() const;
    Vector2& GetScale() const;

    SDL_Rect* GetResultTransform();

private:
    std::unique_ptr<Vector2> position;
    std::unique_ptr<Vector2> scale;
    // rotation?

    SDL_Rect resultRect;
    SDL_Rect sourceRect;
};
