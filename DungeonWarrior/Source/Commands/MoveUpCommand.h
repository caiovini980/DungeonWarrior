#pragma once

#include "../Interfaces/Command.h"

class MoveUpCommand : public Command
{
public:
    void Execute(std::shared_ptr<Player>& player) override
    {
        player->MoveUp();
    }
};