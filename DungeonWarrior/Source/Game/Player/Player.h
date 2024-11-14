﻿#pragma once
#include <memory>
#include <string>

#include "Utils/Vector2.h"
#include "Utils/ConfigHandler.h"

#include "Engine/GameObject.h"

// Forward declarations
class Sprite;
class Transform;
class BoxCollider;
class CollisionManager;
struct SDL_Renderer;

class Player : public GameObject
{
public:
    Player();
    ~Player() override = default;
    
    void SetupPlayer(const PlayerConfig& config);
    
    void Update() override;

    void UpdatePosition() const;

    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();

    BoxCollider& GetCollider() const;
    
private:
    Vector2 m_MovementDirection{0.0f, 0.0f};

    PlayerConfig m_Config;

    // refactor this, not so important
    std::array<std::string, 2> m_TexturesPaths {
        "Assets/Sprites/player.png",
        "Assets/Sprites/player_green.png"
    };
    
    Sprite* m_Sprite;
    BoxCollider* m_Collider;
};