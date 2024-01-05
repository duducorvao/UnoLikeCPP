#pragma once
#include "TableController.h"
#include "TurnsController.h"
#include "IGameEvents.h"
#include <memory>

class GameController : public IGameEvents, public std::enable_shared_from_this<GameController>
{
private:
    std::shared_ptr<TableController> table_controller_;
    std::shared_ptr<TurnsController> turns_controller_;
    bool is_playing_ {false};
    
    void SetupGame() const;
    void SetupCards() const;
    void SetupPlayers() const;
    void GameLoop() const;

    void EndGame() override;

public:
    GameController() = default;
    void Play();
    void Initialize();
};
