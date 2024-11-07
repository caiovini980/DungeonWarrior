#pragma once

#include "../Interfaces/Command.h"

class MoveRightCommand : public Command
{
public:
    void Execute(std::shared_ptr<Player>& player) override
    {
        player->MoveRight();
    }
};
