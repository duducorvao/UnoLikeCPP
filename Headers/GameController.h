#pragma once
#include <memory>
#include "TableController.h"
#include "TurnsController.h"

class GameController
{
private:
    std::unique_ptr<TableController> table_controller_;
    std::unique_ptr<TurnsController> turns_controller_;
    
    void SetupGame();
    void SetupPlayers();
    void SetupCards();
    void StartGame();

public:
    GameController() = default;
    void Play();
    void Initialize();
};
