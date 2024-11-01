#pragma once
#include "../Objects/Player/Player.h"

// all the commands are going to be related to user input, so it could be referencing the player himself
class Command
{
public:
    virtual ~Command() = default;
    virtual void Execute(std::shared_ptr<Player> player) = 0;
};
