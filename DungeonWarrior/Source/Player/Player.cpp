﻿#include "Player.h"
#include "../Components/Transform/Transform.h"
#include "../Components/Sprite/Sprite.h"
#include "../Components/Collision/BoxCollider.h"

Player::Player()
{
    GetTransform()->SetPosition(100, 100);
    m_Sprite = &AddComponent<Sprite>();
}

// Player::Player(SDL_Renderer& renderer, CollisionManager& collisionManager, ConfigHandler& configHandler)
//     : m_Config(configHandler.GetPlayerConfig())
// {
//     // Add items to the skins array
//     
//     GetTransform()->SetPosition(100, 100);
//     
//     m_Sprite = &AddComponent<Sprite>();
//     m_Sprite->SetTexture((m_TexturesPaths)[m_Config.textureIndex].c_str());
//
//     // m_Collider = collisionManager.CreateCollider<BoxCollider>(*m_Transform, CollisionTypes::PLAYER);
// }

void Player::SetupPlayer(const PlayerConfig& config)
{
    m_Config = config;
    m_Sprite->SetTexture((m_TexturesPaths)[m_Config.textureIndex].c_str());
}

// void Player::Render()
// {
    // if (m_Sprite->GetTexture() != nullptr && m_Sprite->GetRenderer() != nullptr)
    // {
    //     SDL_RenderCopy(m_Sprite->GetRenderer(), m_Sprite->GetTexture(), nullptr, m_Transform->GetResultTransform());
    // }
// }

void Player::Update()
{
    UpdatePosition();
    
    m_MovementDirection.m_X = 0.0f;
    m_MovementDirection.m_Y = 0.0f;
    
    GetTransform()->SetScale(m_Config.sizeX, m_Config.sizeY);
    // m_Collider->UpdateCollider();
}


// void Player::Destroy()
// {
// }

void Player::UpdatePosition() const
{
    Vector2 normDir = m_MovementDirection.Normalized();
    normDir *= m_Config.speed;
    
    GetTransform()->AddPosition(normDir);
}

void Player::MoveRight()
{
    m_MovementDirection.m_X = 1;
}

void Player::MoveLeft()
{
    m_MovementDirection.m_X = -1;
}

void Player::MoveUp()
{
    m_MovementDirection.m_Y = -1;
}

void Player::MoveDown()
{
    m_MovementDirection.m_Y = 1;
}

BoxCollider& Player::GetCollider() const
{
    if (m_Collider == nullptr)
    {
        std::cerr << "ERROR: Class 'Player' don't have a collider.\n";
    }
    
    return *m_Collider;
}
