#include "InputSystem.h"

#include <SDL_keyboard.h>

InputSystem::InputSystem()
{
    Initialize();
}

void InputSystem::Initialize()
{
    m_State.keyboardState.m_CurrentState = SDL_GetKeyboardState(nullptr);
    SDL_memset(m_State.keyboardState.m_PreviousState, 0, SDL_NUM_SCANCODES);
}

void InputSystem::Shutdown()
{
}

void InputSystem::PrepareForUpdate()
{
    // copy from the current buffer to the previous buffer
    SDL_memcpy(m_State.keyboardState.m_PreviousState, m_State.keyboardState.m_CurrentState, SDL_NUM_SCANCODES);
}

void InputSystem::Update()
{
}

const InputState& InputSystem::GetState() const
{
    return m_State;
}
