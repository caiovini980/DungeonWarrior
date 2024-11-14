#include "Player.h"
#include "Engine/Components/Transform/Transform.h"
#include "Engine/Components/Sprite/Sprite.h"
#include "Engine/Components/Collision/BoxCollider.h"

Player::Player()
{
    GetTransform()->SetPosition(100, 100);
    m_Sprite = &AddComponent<Sprite>();
    m_Collider = &AddComponent<BoxCollider>();
}

void Player::SetupPlayer(const PlayerConfig& config)
{
    m_Config = config;
    m_Sprite->SetTexture((m_TexturesPaths)[m_Config.textureIndex].c_str());
    m_Collider->SetupCollider(CollisionTypes::PLAYER);
    m_Collider->SetCollisionMapValue(CollisionTypes::WALL, true);
}

void Player::Update()
{
    UpdatePosition();
    
    m_MovementDirection.m_X = 0.0f;
    m_MovementDirection.m_Y = 0.0f;
    
    GetTransform()->SetScale(m_Config.sizeX, m_Config.sizeY);
}

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
