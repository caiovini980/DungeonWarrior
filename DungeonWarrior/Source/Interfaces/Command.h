#pragma once
#include "../Player/Player.h"

class Command
{
public:
    virtual ~Command() = default;
    virtual void Execute(std::shared_ptr<Player>& gameObject) = 0;
};
