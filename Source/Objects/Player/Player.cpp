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
}

void Player::Destroy()
{
}

void Player::ProcessInput(const InputState& state)
{
    CheckVerticalMovement(state);
    CheckHorizontalMovement(state);
}

void Player::CheckVerticalMovement(const InputState& state)
{
    KeyboardState keyboardState = state.keyboardState;
    
    // Move vertically
    if (keyboardState.GetKeyState(SDL_SCANCODE_S) == Held)
    {
        verticalStepCount++;
    }

    if (keyboardState.GetKeyState(SDL_SCANCODE_W) == Held)
    {
        verticalStepCount--;
    }
    
    transform->SetPosition(transform->GetPosition().x, verticalStepCount * config.speed);
}

void Player::CheckHorizontalMovement(const InputState& state)
{
    KeyboardState keyboardState = state.keyboardState;
    
    // Move horizontally
    if (keyboardState.GetKeyState(SDL_SCANCODE_A) == Held)
    {
        horizontalStepCount--;
    }

    if (keyboardState.GetKeyState(SDL_SCANCODE_D) == Held)
    {
        horizontalStepCount++;
    }
    
    transform->SetPosition(horizontalStepCount * config.speed, transform->GetPosition().y);
}


