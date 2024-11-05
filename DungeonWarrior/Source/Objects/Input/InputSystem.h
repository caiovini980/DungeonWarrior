#pragma once
#include <memory>
#include <SDL_events.h>

#include "KeyboardState.h"

struct InputState
{
    KeyboardState keyboardState;
};

class InputSystem
{
public:
    InputSystem();
    ~InputSystem();
    
    void Initialize();
    void Shutdown();

    void PrepareForUpdate();
    void Update();

    const InputState& GetState() const;

private:
    InputState m_State;
};
