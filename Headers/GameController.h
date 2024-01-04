#pragma once
#include "TableController.h"
#include "TurnsController.h"
#include <memory>

class GameController
{
private:
    std::unique_ptr<TableController> table_controller_;
    std::unique_ptr<TurnsController> turns_controller_;
    
    void SetupGame() const;
    void SetupPlayers() const;
    void SetupCards() const;
    void StartGame();

public:
    GameController() = default;
    void Play() const;
    void Initialize();
};
