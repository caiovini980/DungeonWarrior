#include "Player.h"

Player::Player(SDL_Renderer& renderer, ConfigHandler& configHandler)
    : m_Config(configHandler.GetPlayerConfig())
{
    (*m_AvailableTextures)[0] = "Assets/Sprites/player.png";
    (*m_AvailableTextures)[1] = "Assets/Sprites/player_green.png";
    
    m_Transform = std::make_unique<Transform>();
    m_Transform->SetPosition(100, 100);
    
    m_Sprite = std::make_unique<Sprite>(renderer);
    m_Sprite->SetTexture((*m_AvailableTextures)[m_Config.textureIndex].c_str());

    // TODO change the way we get this tag, maybe add it to some global file
    // TODO Create this on a separated class
    m_Collider = std::make_unique<BoxCollider>(*m_Transform, m_Tag);
}

void Player::Render()
{
    if (m_Sprite->GetTexture() != nullptr && m_Sprite->GetRenderer() != nullptr)
    {
        SDL_RenderCopy(m_Sprite->GetRenderer(), m_Sprite->GetTexture(), nullptr, m_Transform->GetResultTransform());
    }
}

void Player::Update()
{
    UpdatePosition();
    
    m_MovementDirection.m_X = 0.0f;
    m_MovementDirection.m_Y = 0.0f;
    
    m_Transform->SetScale(m_Config.sizeX, m_Config.sizeY);
    m_Collider->UpdateCollider();
}

void Player::Destroy()
{
}

void Player::UpdatePosition() const
{
    Vector2 normDir = m_MovementDirection.Normalized();
    normDir *= m_Config.speed;
    
    m_Transform->AddPosition(normDir);
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
