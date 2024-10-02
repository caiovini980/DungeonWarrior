#include "Player.h"

#include <iostream>

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
    transform->SetScale(config.sizeX, config.sizeY);
    Move();
}

void Player::Destroy()
{
}

void Player::Move()
{
    count++;
    transform->SetPosition(count * config.speed, transform->GetPosition().y);
}

