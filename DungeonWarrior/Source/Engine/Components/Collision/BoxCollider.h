#pragma once
#include <SDL_rect.h>

#include "Collider.h"
#include "CollisionTags.h"

class BoxCollider : public Collider
{
public:
    BoxCollider();
    ~BoxCollider() override = default;
    
    void SetupCollider(CollisionTags collisionTag) override;
    
    const SDL_Rect& GetCollider() const;

private:
    void Update() override;

    SDL_Rect m_Collider;
};
