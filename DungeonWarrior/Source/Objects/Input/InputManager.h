#pragma once

#include "../Player/Player.h"
#include "../../Interfaces/Command.h"

#include "../../Commands/MoveLeftCommand.h"
#include "../../Commands/MoveRightCommand.h"
#include "../../Commands/MoveUpCommand.h"
#include "../../Commands/MoveDownCommand.h"

class InputManager
{
public:
    InputManager(std::shared_ptr<Player> player);

    void HandleInput(const InputState& state) const;

private:
    std::shared_ptr<Player> player;
    
    std::unique_ptr<Command> buttonD;
    std::unique_ptr<Command> buttonA;
    
    std::unique_ptr<Command> buttonW;
    std::unique_ptr<Command> buttonS;
};
