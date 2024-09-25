#include "Player.h"

#include <iostream>

Player::Player(SDL_Renderer& renderer)
{
    transform = std::make_unique<Transform>();
    
    sprite = std::make_unique<Sprite>(renderer);
    sprite->SetTexture(&availableTextures[0]);
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
    transform->SetScale(64, 64);
    Move();
}

void Player::Destroy()
{
}

void Player::Move()
{
    count++;
    transform->SetPosition(count, transform->GetPosition().y);
}

