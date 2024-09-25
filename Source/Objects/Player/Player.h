#pragma once
#include <memory>
#include <SDL_render.h>
#include <SDL_image.h>
#include <unordered_map>

#include "../../Interfaces/GameObject.h"

#include "../../Components/Sprite/Sprite.h"
#include "../../Components/Transform/Transform.h"


class Player : GameObject
{
public:
    Player(SDL_Renderer& renderer);
    void Render() override;
    void Update() override;
    void Destroy() override;

    void Move();
    
private:
    std::unique_ptr<Sprite> sprite;
    std::unique_ptr<Transform> transform;

    const char* availableTextures {
        "Assets/Sprites/player.png"
    };
    
    float count{0.0f};

};