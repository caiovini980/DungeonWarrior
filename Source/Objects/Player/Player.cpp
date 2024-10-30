#include "Player.h"

Player::Player(SDL_Renderer& renderer, ConfigHandler& configHandler)
    : config(configHandler.GetPlayerConfig())
{
    transform = std::make_unique<Transform>();
    
    sprite = std::make_unique<Sprite>(renderer);
    sprite->SetTexture(availableTextures[config.textureIndex]);
}

void Player::Render()
{
    if (sprite->GetTexture() != nullptr && sprite->GetRenderer() != nullptr)
    {
        SDL_RenderCopy(sprite->GetRenderer(), sprite->GetTexture(), nullptr, transform->GetResultTransform());
    }
}

void Player::Update()
{
    UpdatePosition();
    
    movementDirection.x = 0.0f;
    movementDirection.y = 0.0f;
    
    transform->SetScale(config.sizeX, config.sizeY);
}

void Player::Destroy()
{
}

void Player::UpdatePosition() const
{
    Vector2 normDir = movementDirection.Normalized();
    normDir *= config.speed;
    
    transform->AddPosition(normDir);
}

void Player::MoveRight()
{
    movementDirection.x = 1;
}

void Player::MoveLeft()
{
    movementDirection.x = -1;
}

void Player::MoveUp()
{
    movementDirection.y = -1;
}

void Player::MoveDown()
{
    movementDirection.y = 1;
}
