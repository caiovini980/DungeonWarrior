#include "Player.h"
#include "Engine/Components/Transform/Transform.h"
#include "Engine/Components/Sprite/Sprite.h"
#include "Engine/Components/Collision/BoxCollider.h"

Player::Player()
{
    GetTransform()->SetPosition(100, 100);
    m_Sprite = AddComponent<Sprite>();
    m_Collider = AddComponent<BoxCollider>();
}

void Player::SetupPlayer(const PlayerConfig& config)
{
    m_Config = config;
    if (auto sprite = m_Sprite.lock())
    {
        sprite->SetTexture(m_TexturesPaths[m_Config.textureIndex].c_str());
    }

    if (auto collider = m_Collider.lock())
    {
        collider->SetupCollider(CollisionTags::PLAYER);
        collider->SetCollisionMapValue(CollisionTags::WALL, true);
        collider->SetCollisionMapValue(CollisionTags::OBSTACLE, true);
    }
}

void Player::Update()
{
    UpdatePosition();
    GetTransform()->SetScale(m_Config.sizeX, m_Config.sizeY);
}

void Player::LateUpdate()
{
    GetTransform()->SetDirection(0.0f, 0.0f);
}

void Player::UpdatePosition()
{
    Vector2 normDir = GetTransform()->GetDirection().Normalized();
    normDir *= m_Config.speed;
    
    GetTransform()->AddPosition(normDir);
}

void Player::MoveRight()
{
    GetTransform()->SetDirectionHorizontally(1);
}

void Player::MoveLeft()
{
    GetTransform()->SetDirectionHorizontally(-1);
}

void Player::MoveUp()
{
    GetTransform()->SetDirectionVertically(-1);
}

void Player::MoveDown()
{
    GetTransform()->SetDirectionVertically(1);
}

BoxCollider& Player::GetCollider() const
{
    if (m_Collider.lock() == nullptr)
    {
        std::cerr << "ERROR: Class 'Player' don't have a collider.\n";
    }
    
    return *m_Collider.lock();
}
