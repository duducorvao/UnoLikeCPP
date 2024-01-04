#pragma once
#include "TableController.h"
#include "TurnsController.h"
#include <memory>

class GameController
{
private:
    std::shared_ptr<TableController> table_controller_;
    std::shared_ptr<TurnsController> turns_controller_;
    
    void SetupGame() const;
    void SetupCards() const;
    void SetupPlayers() const;
    void StartGame() const;

public:
    GameController() = default;
    void Play() const;
    void Initialize();
};
