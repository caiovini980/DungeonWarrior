#pragma once
#include <SDL_scancode.h>

enum ButtonState
{
    None = 0,
    Pressed,
    Released,
    Held
};

class KeyboardState
{
public:
    KeyboardState();
    ~KeyboardState() = default;
    
    // Friend so InputSystem can easily update it
    // friend class InputSystem;

    // Get just the boolean true/false value of key
    bool GetKeyValue(SDL_Scancode keyCode) const;

    // Get a state based on current and previous frame
    ButtonState GetKeyState(SDL_Scancode keyCode) const;

    // TODO remade this
    const Uint8* m_CurrentState;
    Uint8 m_PreviousState[SDL_NUM_SCANCODES];
};
