#pragma once

#include "../Interfaces/Command.h"

class MoveLeftCommand : public Command
{
public:
    void Execute(std::shared_ptr<Player>& player) override
    {
        player->MoveLeft();
    }
};