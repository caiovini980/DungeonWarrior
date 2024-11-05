#pragma once
#include <SDL_rect.h>
#include <string>

#include "../Transform/Transform.h"

class BoxCollider
{
public:
    BoxCollider(Transform& entityTransform, std::string& tag);

    void UpdateCollider();

    const SDL_Rect& GetCollider() const;
    const std::string& GetTag() const;
    
private:
    
    std::shared_ptr<Transform> m_Transform;
    std::unique_ptr<std::string> m_Tag;
    
    SDL_Rect m_Collider;
};
