#pragma once
#include <iostream>
#include <memory>

#include "InputSystem.h"
#include "../../Interfaces/Command.h"

#include "../../Commands/MoveLeftCommand.h"
#include "../../Commands/MoveRightCommand.h"
#include "../../Commands/MoveUpCommand.h"
#include "../../Commands/MoveDownCommand.h"


class GameObject;

class InputManager
{
public:
    InputManager(Player* player);

    void HandleInput(const InputState& state) const;

private:
    Player* m_Player;
    
    // std::unique_ptr<Command> m_ButtonD;
    // std::unique_ptr<Command> m_ButtonA;
    // std::unique_ptr<Command> m_ButtonW;
    // std::unique_ptr<Command> m_ButtonS;
};
