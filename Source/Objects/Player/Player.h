#pragma once
#include <memory>
#include <SDL_render.h>
#include <SDL_image.h>
#include <unordered_map>

#include "../../Interfaces/GameObject.h"

#include "../../Components/Sprite/Sprite.h"
#include "../../Components/Transform/Transform.h"
#include "../../Utils/ConfigHandler.h"
#include "../Input/InputSystem.h"


class Player : GameObject
{
public:
    Player(SDL_Renderer& renderer, ConfigHandler& configHandler);
    void Render() override;
    void Update() override;
    void Destroy() override;

    void ProcessInput(const InputState& state);

    void CheckHorizontalMovement(const InputState& state);
    void CheckVerticalMovement(const InputState& state);
    
private:
    std::unique_ptr<Sprite> sprite;
    std::unique_ptr<Transform> transform;
    
    Vector2 movementDirection{0.0f, 0.0f};

    PlayerConfig config;

    const char* availableTextures[2] {
        "Assets/Sprites/player.png",
        "Assets/Sprites/player_green.png"
    };
    
    float horizontalStepCount{0.0f};
    float verticalStepCount{0.0f};

};
