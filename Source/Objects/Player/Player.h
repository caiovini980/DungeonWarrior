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

    void UpdatePosition() const;

    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();
    
private:
    std::unique_ptr<Sprite> sprite;
    std::unique_ptr<Transform> transform;
    
    Vector2 movementDirection{0.0f, 0.0f};

    PlayerConfig config;

    const char* availableTextures[2] {
        "Assets/Sprites/player.png",
        "Assets/Sprites/player_green.png"
    };
};
