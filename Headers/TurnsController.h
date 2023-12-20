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
    void NextTurn();
    void ShufflePlayers();
    void SetOrder(EPlayOrder order);
    const std::vector<std::shared_ptr<Player>> GetPlayers();
    
private:
    EPlayOrder play_order_ = EPlayOrder::Clockwise;
    std::vector<std::shared_ptr<Player>> players_;
    std::shared_ptr<Player> current_player;
};
