#pragma once

#include "../Interfaces/Command.h"
#include "../Objects/Player/Player.h"

class MoveUpCommand : public Command
{
public:
    void Execute(const std::shared_ptr<Player> player) override
    {
        player->MoveUp();
    }
};