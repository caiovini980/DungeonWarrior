#pragma once
#include <SDL_rect.h>

#include "Collider.h"
#include "../../Core/Tags/CollisionTags.h"
#include "../Transform/Transform.h"

class BoxCollider : public Collider
{
public:
    BoxCollider(const std::shared_ptr<Transform>& entityTransform, CollisionTypes collisionType);
    ~BoxCollider() override = default;
    
    void UpdateCollider();
    
    const CollisionTypes& GetCollisionType() const override;
    const SDL_Rect& GetCollider() const;

private:
    SDL_Rect m_Collider;
};
