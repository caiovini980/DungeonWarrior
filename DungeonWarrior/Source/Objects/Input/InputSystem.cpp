#include "InputSystem.h"

InputSystem::InputSystem()
{
    Initialize();
}

InputSystem::~InputSystem()
{
}

void InputSystem::Initialize()
{
    state.keyboardState.currentState = SDL_GetKeyboardState(nullptr);
    SDL_memset(state.keyboardState.previousState, 0, SDL_NUM_SCANCODES);
}

void InputSystem::Shutdown()
{
}

void InputSystem::PrepareForUpdate()
{
    // copy from the current buffer to the previous buffer
    SDL_memcpy(state.keyboardState.previousState, state.keyboardState.currentState, SDL_NUM_SCANCODES);
}

void InputSystem::Update()
{
}

const InputState& InputSystem::GetState() const
{
    return state;
}
