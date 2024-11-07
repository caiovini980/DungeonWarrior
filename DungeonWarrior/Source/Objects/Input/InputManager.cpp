#include "InputManager.h"

InputManager::InputManager(const std::shared_ptr<Player>& player)
    : m_Player(player)
{
    m_ButtonD = std::make_unique<MoveRightCommand>();
    m_ButtonA = std::make_unique<MoveLeftCommand>();

    m_ButtonW = std::make_unique<MoveUpCommand>();
    m_ButtonS = std::make_unique<MoveDownCommand>();
    
    std::cout << "InputManager Initialized.\n\n";
}

void InputManager::HandleInput(const InputState& state)
{
    KeyboardState keyboardState = state.keyboardState;

    // Move vertically
    if (keyboardState.GetKeyState(SDL_SCANCODE_S) == Held)
    {
        m_ButtonS->Execute(m_Player);
    }

    if (keyboardState.GetKeyState(SDL_SCANCODE_W) == Held)
    {
        m_ButtonW->Execute(m_Player);
    }

    // Move horizontally
    if (keyboardState.GetKeyState(SDL_SCANCODE_A) == Held)
    {
        m_ButtonA->Execute(m_Player);
    }

    if (keyboardState.GetKeyState(SDL_SCANCODE_D) == Held)
    {
        m_ButtonD->Execute(m_Player);
    }
}
