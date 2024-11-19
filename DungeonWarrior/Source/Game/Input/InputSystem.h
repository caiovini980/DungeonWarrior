#pragma once

#include "KeyboardState.h"

struct InputState
{
    KeyboardState keyboardState;
};

class InputSystem
{
public:
    InputSystem();
    ~InputSystem() = default;
    
    void Initialize();
    void Shutdown();

    void PrepareForUpdate();
    void Update();

    const InputState& GetState() const;

private:
    InputState m_State;
};
