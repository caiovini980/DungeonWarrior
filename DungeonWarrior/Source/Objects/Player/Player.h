#pragma once
#include <memory>
#include <SDL_render.h>
#include <SDL_image.h>
#include <unordered_map>

#include "../../Interfaces/GameObject.h"

#include "../../Utils/ConfigHandler.h"

#include "../../Components/Sprite/Sprite.h"
#include "../../Components/Transform/Transform.h"
#include "../../Components/Collision/BoxCollider.h"
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

    BoxCollider& GetCollider() const;
    
private:
    std::unique_ptr<Sprite> m_Sprite;
    std::unique_ptr<Transform> m_Transform;
    std::unique_ptr<BoxCollider> m_Collider;

    std::string m_Tag = "player";
    
    Vector2 m_MovementDirection{0.0f, 0.0f};

    PlayerConfig m_Config;

    std::unique_ptr<std::array<std::string, 2>> m_AvailableTextures {
        std::make_unique<std::array<std::string, 2>>()
    };
};
