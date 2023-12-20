#pragma once
#include <memory>
#include "../Headers/TableController.h"
#include "../Headers/TurnsController.h"

class GameController
{
private:
    std::unique_ptr<TableController> table_controller_;
    std::unique_ptr<TurnsController> turns_controller_;

public:
    GameController();
    void Initialize();
    void Play();
    void SetupGame();
    void SetupPlayers();
    void StartGame();    
};
