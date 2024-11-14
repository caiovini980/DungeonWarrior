#pragma once
#include <iostream>
#include <memory>

#include "InputSystem.h"

class Player;

class InputManager
{
public:
    InputManager(Player* player);

    void HandleInput(const InputState& state) const;

private:
    Player* m_Player;
};
