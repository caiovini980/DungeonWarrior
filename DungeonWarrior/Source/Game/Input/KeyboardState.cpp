#include "KeyboardState.h"

KeyboardState::KeyboardState()
{
}

bool KeyboardState::GetKeyValue(SDL_Scancode keyCode) const
{
    return m_CurrentState[keyCode] == 1;
}

ButtonState KeyboardState::GetKeyState(SDL_Scancode keyCode) const
{
    // state options
    // previous = 0 and current = 0 -> NONE
    // previous = 0 and current = 1 -> PRESSED
    // previous = 1 and current = 0 -> RELEASED
    // previous = 1 and current = 1 -> HOLD
    
    if (m_PreviousState[keyCode] == 0)
    {
        if (m_CurrentState[keyCode] == 0)
        {
            return None;
        }
        
        return Pressed;
    }

    if (m_CurrentState[keyCode] == 0)
    {
        return Released;
    }

    return Held;
}
