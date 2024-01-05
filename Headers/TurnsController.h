#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Card.h"

class IGameEvents;
class TableController;
class Player;

class TurnsController
{
public:
    enum class EPlayOrder
    {
        Clockwise,
        Anticlockwise
    };
    
    TurnsController(const std::shared_ptr<IGameEvents>& game_events_handler); 
    void Initialize(const std::shared_ptr<TableController>& table_controller);
    void SetupTurns(std::vector<std::shared_ptr<Player>> players);
    void PlayTurn() const;
    void NextTurn();
    void NextPlayer();
    void ShufflePlayers();
    void SetOrder(EPlayOrder order);
    int GetPlayerOption(const std::shared_ptr<Card>& top_card_shared) const;
    void ForcePlayerToBuyCards(const std::string& message, int amount) const;
    const std::vector<std::shared_ptr<Player>>& GetPlayers();
    const std::shared_ptr<Player>& GetCurrentPlayer() const;
    
private:
    std::shared_ptr<IGameEvents> game_events_handler_;
    std::shared_ptr<TableController> table_controller_;
    EPlayOrder play_order_ = EPlayOrder::Clockwise;
    std::vector<std::shared_ptr<Player>> players_;
    std::shared_ptr<Player> current_player;

    size_t current_player_index_ {0};
    size_t players_amount_ {0};
};
