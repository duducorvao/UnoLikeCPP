#include "../Headers/TurnsController.h"
#include "../Headers/GameConsole.h"
#include "../Headers/Player.h"
#include "../Headers/Config.h"
#include "../Headers/IGameEvents.h"
#include "../Headers/TableController.h"
#include <algorithm>
#include <chrono>
#include <random>
#include <sstream>

#define MOD_ARITH(a, n) ((((a) % (n)) + (n)) % (n)) // ((a % n) + n) % n

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
    current_player_ = *players_.begin();
}

std::shared_ptr<Card> TurnsController::PlayChosenCard(const int option) const
{
    const int chosen_card_index = option - 1;
    auto chosen_card = current_player_->GetCardAt(chosen_card_index);
    table_controller_->PlaceCard(chosen_card);
    
    current_player_->RemoveCardFromHand(chosen_card_index);
    return chosen_card;
}

void TurnsController::PlayTurn()
{
    GameConsole::ClearScreen();
    GameConsole::PrintLine("----- New Turn -----");
    
    table_controller_->PrintTopCard();
    const std::weak_ptr<Card> top_card = table_controller_->GetTopCard();
    const std::shared_ptr<Card> top_card_shared = top_card.lock();

    PrintPlayersOrder();
    GameConsole::PrintLine(current_player_->GetName() + "'s turn:");
    
    current_player_->PrintHand();
    
    CheckForPlusTwoCardBuying(top_card_shared);
    
    const auto matching_cards = current_player_->GetHandMatchingCards(top_card_shared);
    if (matching_cards.empty())
    {
        // If the player still doesn't have a matching card, buy a card and skip;
        ForcePlayerToBuyCards("Player " + current_player_->GetName() + " doesn't have a card that can be used", 1);
        return;
    }
    
    if(current_player_->GetHandSize() == 1)
    {
        if(!current_player_->GetHasSaidUno())
        {
            // As a penalty for not yelling UNO, the player must buy new cards
            ForcePlayerToBuyCards(
                "Player " + current_player_->GetName() + " didn't yell UNO. Buying " +
                std::to_string(Config::YELL_UNO_PENALTY_CARDS) + " cards.", Config::YELL_UNO_PENALTY_CARDS);
            return;
        }
    }

    const int option = GetPlayerOption(top_card_shared);
    const auto chosen_card = PlayChosenCard(option);

    if (current_player_->GetHandSize() == 0)
    {
        GameConsole::PrintLine("Player " + current_player_->GetName() + " win!!!");
        game_events_handler_->EndGame();
    }

    chosen_card->OnPlaceAction(this);
}

void TurnsController::NextTurn()
{
    NextPlayer();
}

void TurnsController::NextPlayer()
{
    SetNextPlayerIndex();
    current_player_ = players_.at(current_player_index_);
}

void TurnsController::SetNextPlayerIndex()
{
    const int direction = static_cast<int>(play_order_);
    current_player_index_ = MOD_ARITH((static_cast<int>(current_player_index_) + direction), static_cast<int>(players_amount_));
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

void TurnsController::PrintPlayersOrder() const
{
    GameConsole::Print("Player's Order: ");
    for (size_t i = 0; i < players_.size(); ++i)
    {
        i == current_player_index_
            ? GameConsole::SetColor(Config::CURRENT_PLAYER_COLOR)
            : GameConsole::SetColor(Config::CONSOLE_NORMAL_COLOR);

        GameConsole::Print(players_.at(i)->GetName() + " ");
    }

    GameConsole::SetColor(Config::CONSOLE_NORMAL_COLOR);
    GameConsole::PrintLine();
}

void TurnsController::CheckForPlusTwoCardBuying(const std::shared_ptr<Card> top_card_shared)
{
    // force_buy_card_amount_ being 0, means that this was the card flipped in the game's beginning.
    if (top_card_shared->GetCardType() == Card::ECardType::PlusTwo && force_buy_card_amount_ > 0)
    {
        const auto place_matching_cards = current_player_->GetPlaceMatchingCards(top_card_shared);
        if (place_matching_cards.empty())
        {
            // If the top card is a +2 and the player doesn't have another +2 to play, it will be forced to buy cards.
            ForcePlayerToBuyCards(
                "Player " + current_player_->GetName() + " must buy " + std::to_string(force_buy_card_amount_) +
                " cards", force_buy_card_amount_);

            force_buy_card_amount_ = 0;
        }
    }
}

int TurnsController::GetPlayerOption(const std::shared_ptr<Card>& top_card_shared) const
{
    int option;
    const int player_hand_size = current_player_->GetHandSize();
    do
    {
        const bool player_can_say_uno = current_player_->CanSayUno();
        const bool player_has_said_uno = current_player_->GetHasSaidUno();
        
        std::ostringstream oss;
        oss << "Choose a card to play using the indexes above";
        oss << (player_can_say_uno ? " or input 0 to yell UNO!: " : ": ");
        
        option = GameConsole::Read<int>(oss.str());
        if (!player_has_said_uno)
        {
            current_player_->SetHasSaidUno(player_can_say_uno && option == 0);
        }
        
        if (option > 0 && option <= player_hand_size )
        {
            const auto chosen_card = current_player_->GetCardAt(option - 1);
            
            if(!top_card_shared->CheckUseCondition(chosen_card))
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
    GameConsole::WaitForEnterInput("Press ENTER to buy...");

    current_player_->AddCardsToHand(table_controller_->BuyCards(amount));
    current_player_->PrintHand();
    
    GameConsole::WaitForEnterInput("Press ENTER to continue...");
}

const std::vector<std::shared_ptr<Player>>& TurnsController::GetPlayers()
{
    return this->players_;
}

const std::shared_ptr<Player>& TurnsController::GetCurrentPlayer() const
{
    return current_player_;
}

void TurnsController::HandleReverseCardPlaceAction()
{
    int next_order = static_cast<int>(play_order_) * -1; 
    SetOrder(static_cast<EPlayOrder>(next_order));
}

void TurnsController::HandleJumpCardPlaceAction()
{
    SetNextPlayerIndex();
}

void TurnsController::HandlePlusTwoPlaceAction()
{
    force_buy_card_amount_ += 2;
}