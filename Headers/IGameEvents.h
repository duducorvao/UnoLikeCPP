#pragma once

class IGameEvents
{
public:
    virtual ~IGameEvents() = default;
    virtual void EndGame() = 0;
};
