﻿#include "KeyboardState.h"

KeyboardState::KeyboardState()
{
}

bool KeyboardState::GetKeyValue(SDL_Scancode keyCode) const
{
    return currentState[keyCode] == 1;
}

ButtonState KeyboardState::GetKeyState(SDL_Scancode keyCode) const
{
    // state options
    // previous = 0 and current = 0 -> NONE
    // previous = 0 and current = 1 -> PRESSED
    // previous = 1 and current = 0 -> RELEASED
    // previous = 1 and current = 1 -> HOLD
    
    if (previousState[keyCode] == 0)
    {
        if (currentState[keyCode] == 0)
        {
            return None;
        }
        
        return Pressed;
    }

    if (currentState[keyCode] == 0)
    {
        return Released;
    }

    return Held;
}