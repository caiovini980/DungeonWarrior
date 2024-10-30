#pragma once

#include "../Interfaces/Command.h"
#include "../Objects/Player/Player.h"

class MoveDownCommand : public Command
{
public:
    void Execute(std::shared_ptr<Player> player) override
    {
        player->MoveDown();
    }
};