#pragma once
#include <SDL_rect.h>

#include "Collider.h"
#include "../Transform/Transform.h"

class BoxCollider : public Collider
{
public:
    BoxCollider(const std::shared_ptr<Transform>& entityTransform, const std::shared_ptr<std::string>& tag);

    void UpdateCollider();
    
    const std::string& GetTag() const override;
    const SDL_Rect& GetCollider() const;

private:
    SDL_Rect m_Collider;
};
