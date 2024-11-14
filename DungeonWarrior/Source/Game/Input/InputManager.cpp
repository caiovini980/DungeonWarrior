#include "InputManager.h"

#include "Game/Player/Player.h"

InputManager::InputManager(Player* player)
    : m_Player(player)
{
    std::cout << "InputManager Initialized.\n\n";
}

void InputManager::HandleInput(const InputState& state) const
{
    KeyboardState keyboardState = state.keyboardState;

    // Move vertically
    if (keyboardState.GetKeyState(SDL_SCANCODE_S) == Held)
    {
        m_Player->MoveDown();
    }

    if (keyboardState.GetKeyState(SDL_SCANCODE_W) == Held)
    {
        m_Player->MoveUp();
    }

    // Move horizontally
    if (keyboardState.GetKeyState(SDL_SCANCODE_A) == Held)
    {
        m_Player->MoveLeft();
    }

    if (keyboardState.GetKeyState(SDL_SCANCODE_D) == Held)
    {
        m_Player->MoveRight();
    }
}
