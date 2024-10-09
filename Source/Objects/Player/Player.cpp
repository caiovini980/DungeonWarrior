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
    KeyboardState keyboardState = state.keyboardState;

    movementDirection.x = 0.0f;
    movementDirection.y = 0.0f;

    // Move vertically
    if (keyboardState.GetKeyState(SDL_SCANCODE_S) == Held)
    {
        movementDirection.y = 1;
    }

    if (keyboardState.GetKeyState(SDL_SCANCODE_W) == Held)
    {
        movementDirection.y = -1;
    }

    // Move horizontally
    if (keyboardState.GetKeyState(SDL_SCANCODE_A) == Held)
    {
        movementDirection.x = -1;
    }

    if (keyboardState.GetKeyState(SDL_SCANCODE_D) == Held)
    {
        movementDirection.x = 1;
    }

    Vector2 normDir = movementDirection.Normalized();

    normDir.x *= config.speed;
    normDir.y *= config.speed;
    
    transform->AddPosition(normDir);
}

