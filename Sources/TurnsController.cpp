#include "../Headers/TurnsController.h"

#include "../Headers/GameConsole.h"
#include "../Headers/Player.h"
#include <algorithm>
#include <chrono>
#include <random>
#include <sstream>

#include "../Headers/Config.h"
#include "../Headers/IGameEvents.h"
#include "../Headers/TableController.h"

#define MOD_ARITH(a, n) ((((a) % (n)) + (n)) % (n)) // ((a & n) + n) % n

TurnsController::TurnsController(const std::shared_ptr<IGameEvents>& game_events_handler) : game_events_handler_(game_events_handler)
{
}

void TurnsController::Initialize(const std::shared_ptr<TableController>& table_controller)
{
    table_controller_ = table_controller;
}

void TurnsController::SetupTurns(std::vector<std::shared_ptr<Player>> players)
{
    players_ = std::move(players);
    players_amount_ = players_.size();
    
    ShufflePlayers();
    current_player = *players_.begin();
}

void TurnsController::PlayTurn() const
{
    GameConsole::ClearScreen();
    GameConsole::PrintLine("----- New Turn -----");
    
    table_controller_->PrintTopCard();
    const std::weak_ptr<Card> top_card = table_controller_->GetTopCard();
    const std::shared_ptr<Card> top_card_shared = top_card.lock();
    
    top_card_shared->OnTurnBeginAction();
    
    GameConsole::PrintLine(current_player->GetName() + "'s turn:");
    
    current_player->PrintHand();
    
    const auto matching_cards = current_player->GetMatchingCards(top_card_shared);
    if (matching_cards.empty())
    {
        // Force player to buy cards if they doesn't have any matching one.
        ForcePlayerToBuyCards("Player " + current_player->GetName() + " doesn't have a card that can be used", 1);
        return;
    }
    
    if(current_player->GetHandSize() == 1)
    {
        if(!current_player->GetHasSaidUno())
        {
            // As a penalty for not yelling UNO, the player must buy new cards
            ForcePlayerToBuyCards(
                "Player " + current_player->GetName() + " didn't yell UNO. Buying " +
                std::to_string(Config::YELL_UNO_PENALTY_CARDS) + " cards.", Config::YELL_UNO_PENALTY_CARDS);
            return;
        }
    }

    const int option = GetPlayerOption(top_card_shared);
    
    const int chosen_card_index = option - 1;
    const auto chosen_card = current_player->GetCardAt(chosen_card_index);
    table_controller_->PlaceCard(chosen_card);
    
    current_player->RemoveCardFromHand(chosen_card_index);

    if (current_player->GetHandSize() == 0)
    {
        GameConsole::PrintLine("Player " + current_player->GetName() + " win!!!");
        game_events_handler_->EndGame();
    }

    chosen_card->OnPlaceAction();
}

void TurnsController::NextTurn()
{
    NextPlayer();
}

void TurnsController::NextPlayer()
{
    int direction;
    play_order_ == EPlayOrder::Clockwise ? direction = 1 : direction = -1;
    current_player_index_ = MOD_ARITH((current_player_index_ + direction), players_amount_);
    current_player = players_.at(current_player_index_);
}

void TurnsController::ShufflePlayers()
{
    const unsigned seed = static_cast<const unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(players_.begin(), players_.end(), std::default_random_engine(seed));
}

void TurnsController::SetOrder(EPlayOrder order)
{
    play_order_ = order;
}

int TurnsController::GetPlayerOption(const std::shared_ptr<Card>& top_card_shared) const
{
    int option;
    const int player_hand_size = current_player->GetHandSize();
    do
    {
        const bool player_can_say_uno = current_player->CanSayUno();
        const bool player_has_said_uno = current_player->GetHasSaidUno();
        
        std::ostringstream oss;
        oss << "Choose a card to play using the indexes above";
        oss << (player_can_say_uno ? " or input 0 to yell UNO!: " : ": ");
        
        option = GameConsole::Read<int>(oss.str());
        if (!player_has_said_uno)
        {
            current_player->SetHasSaidUno(player_can_say_uno && option == 0);
        }
        
        if (option > 0 && option <= player_hand_size )
        {
            const auto chosen_card = current_player->GetCardAt(option - 1);
            
            if(!chosen_card->CheckUseCondition(top_card_shared))
            {
                option = 0; // To reset this block
                GameConsole::PrintWarn(chosen_card->GetUsageRule());
            }
        }
    }
    while (option < 1 || option > player_hand_size);

    return option;
}

void TurnsController::ForcePlayerToBuyCards(const std::string& message, int amount) const
{
    GameConsole::PrintWarn(message);
    GameConsole::WaitForAnyInput("Press ENTER to buy...");

    current_player->AddCardsToHand(table_controller_->BuyCards(amount));
    current_player->PrintHand();
    
    GameConsole::WaitForAnyInput("Press ENTER to continue...");
}

const std::vector<std::shared_ptr<Player>>& TurnsController::GetPlayers()
{
    return this->players_;
}

const std::shared_ptr<Player>& TurnsController::GetCurrentPlayer() const
{
    return current_player;
}
