#include "InputManager.h"

InputManager::InputManager(std::shared_ptr<Player> player)
    : player(player)
{
    buttonD = std::make_unique<MoveRightCommand>();
    buttonA = std::make_unique<MoveLeftCommand>();

    buttonW = std::make_unique<MoveUpCommand>();
    buttonS = std::make_unique<MoveDownCommand>();
    
    std::cout << "InputManager Initialized.\n\n";
}

void InputManager::HandleInput(const InputState& state) const
{
    KeyboardState keyboardState = state.keyboardState;

    // Move vertically
    if (keyboardState.GetKeyState(SDL_SCANCODE_S) == Held)
    {
        buttonS->Execute(player);
    }

    if (keyboardState.GetKeyState(SDL_SCANCODE_W) == Held)
    {
        buttonW->Execute(player);
    }

    // Move horizontally
    if (keyboardState.GetKeyState(SDL_SCANCODE_A) == Held)
    {
        buttonA->Execute(player);
    }

    if (keyboardState.GetKeyState(SDL_SCANCODE_D) == Held)
    {
        buttonD->Execute(player);
    }
}
