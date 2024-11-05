#pragma once

#include "../Interfaces/Command.h"
#include "../Objects/Player/Player.h"

class MoveLeftCommand : public Command
{
public:
    void Execute(const std::shared_ptr<Player> player) override
    {
        player->MoveLeft();
    }
};