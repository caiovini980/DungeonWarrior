#pragma once
#include <memory>
#include <string>

#include "../Utils/Vector2.h"
#include "../Utils/ConfigHandler.h"

#include "../Core/GameObject.h"

// Forward declarations
class Sprite;
class Transform;
class BoxCollider;
class CollisionManager;
struct SDL_Renderer;

class Player : public GameObject
{
public:
    Player() = default;
    ~Player() override = default;
    Player(SDL_Renderer& renderer, CollisionManager& collisionManager, ConfigHandler& configHandler);
    
    void Update() override;

    void UpdatePosition() const;

    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();

    BoxCollider& GetCollider() const;
    
private:
    std::unique_ptr<BoxCollider> m_Collider;
    
    Vector2 m_MovementDirection{0.0f, 0.0f};

    PlayerConfig m_Config;

    std::unique_ptr<std::array<std::string, 2>> m_AvailableTextures;
};
