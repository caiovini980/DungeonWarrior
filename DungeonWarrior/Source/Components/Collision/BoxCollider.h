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
    
    std::shared_ptr<Transform> transform;
    
    SDL_Rect collider;
    std::unique_ptr<std::string> tag;
};
