#pragma once
#include <memory>
#include <vector>

class Player;

class TurnsController
{
public:
    enum class EPlayOrder
    {
        Clockwise,
        Anticlockwise
    };
    
    void Initialize(std::vector<std::shared_ptr<Player>> players);
    void SetupTurns();
    void PlayTurn();
    void NextTurn();
    void NextPlayer();
    void ShufflePlayers();
    void SetOrder(EPlayOrder order);
    const std::vector<std::shared_ptr<Player>>& GetPlayers();
    
private:
    EPlayOrder play_order_ = EPlayOrder::Clockwise;
    std::vector<std::shared_ptr<Player>> players_;
    std::shared_ptr<Player> current_player;

    size_t current_player_index_ {0};
    size_t players_amount_ {0};
};
