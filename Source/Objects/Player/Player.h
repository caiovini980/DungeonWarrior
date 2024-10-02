#pragma once
#include <memory>
#include <SDL_render.h>
#include <SDL_image.h>
#include <unordered_map>

#include "../../Interfaces/GameObject.h"

#include "../../Components/Sprite/Sprite.h"
#include "../../Components/Transform/Transform.h"
#include "../../Utils/ConfigHandler.h"


class Player : GameObject
{
public:
    Player(SDL_Renderer& renderer, ConfigHandler& configHandler);
    void Render() override;
    void Update() override;
    void Destroy() override;

    void Move();
    
private:
    std::unique_ptr<Sprite> sprite;
    std::unique_ptr<Transform> transform;

    PlayerConfig& config;

    const char* availableTextures[2] {
        "Assets/Sprites/player.png",
        "Assets/Sprites/player_green.png"
    };
    
    float count{0.0f};

};
