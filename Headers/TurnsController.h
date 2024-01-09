#pragma once
#include "Card.h"
#include "ICardActionHandler.h"
#include <memory>
#include <string>
#include <vector>

class IGameEvents;
class TableController;
class Player;

class TurnsController : public ICardActionHandler
{
public:

    enum class EPlayOrder
    {
        Clockwise = 1,
        Anticlockwise = -1
    };
    
    TurnsController(const std::shared_ptr<IGameEvents>& game_events_handler); 
    void Initialize(const std::shared_ptr<TableController>& table_controller);
    void SetupTurns(std::vector<std::shared_ptr<Player>> players);
    void PlayTurn();
    void NextTurn();
    void NextPlayer();
    void SetNextPlayerIndex();
    void ShufflePlayers();
    void SetOrder(EPlayOrder order);
    void PrintPlayersOrder() const;
    void CheckForPlusTwoCardBuying(const std::shared_ptr<Card>& top_card_shared);
    std::shared_ptr<Card> PlayChosenCard(int option) const;
    int GetPlayerOption(const std::shared_ptr<Card>& top_card_shared) const;
    void ForcePlayerToBuyCards(const std::string& message, int amount) const;
    const std::vector<std::shared_ptr<Player>>& GetPlayers();
    const std::shared_ptr<Player>& GetCurrentPlayer() const;
    
    void HandleReverseCardPlaceAction() override;
    void HandleJumpCardPlaceAction() override;
    void HandlePlusTwoPlaceAction() override;

private:
    std::shared_ptr<IGameEvents> game_events_handler_;
    std::shared_ptr<TableController> table_controller_;
    EPlayOrder play_order_ = EPlayOrder::Clockwise;
    std::vector<std::shared_ptr<Player>> players_;
    std::shared_ptr<Player> current_player_;

    size_t current_player_index_ {0};
    size_t players_amount_ {0};
    int force_buy_card_amount_ {0};
};
