#include "../Headers/TurnsController.h"

#include "../Headers/GameConsole.h"
#include "../Headers/Player.h"
#include <algorithm>
#include <chrono>
#include <random>

#include "../Headers/TableController.h"

#define MOD_ARITH(a, n) ((((a) % (n)) + (n)) % (n)) // ((a & n) + n) % n

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
    
    // 1 - Printa a carta do topo;
    table_controller_->PrintTopCard();
    std::weak_ptr<Card> top_card = table_controller_->GetTopCard();
    std::shared_ptr<Card> top_card_shared = top_card.lock();

    // 2 - Checa se a carta do topo possui algum efeito de começo de turno
        // 2.1 - Se sim, aplica efeito.
    top_card_shared->OnTurnBeginAction();

    // 3 - Printa mensagem informando quem é o jogador que irá jogar
    GameConsole::PrintLine(current_player->GetName() + "'s turn:");
    
    // 4 - Printa a mão do jogador com as opções
    current_player->PrintHand();
    
    // 5 - Checa se o jogador tem alguma carta que é possível ser jogada.
    const auto matching_cards = current_player->GetMatchingCards(top_card_shared);

    // If empty, it means the player can't play this turn and must buy a card.
    if (matching_cards.empty())
    {
        // 5.1 - Jogador compra uma carta e passa o turno.
        GameConsole::PrintWarn("Player " + current_player->GetName() + " doesn't have a card that can be used");
        GameConsole::WaitForAnyInput("Press ENTER to buy a card...");

        current_player->AddCardsToHand(table_controller_->BuyCards(1));
    }
    
    // 6 - Capta a opção que o jogador inseriu
    int option {0};
    const int player_hand_size = current_player->GetHandSize();
    do
    {
        option = GameConsole::Read<int>("Choose a card to play using the indexes above: ");

        // 7 - Checa se a carta escolhida pode ser jogada
        if (option > 0 && option <= player_hand_size )
        {
            const auto chosen_card = current_player->GetCardAt(option - 1);
            
            if(!chosen_card->CheckUseCondition(top_card_shared))
            {
                // 7.1 - Se não pode, informa o pq e printa a mão novamente
                option = 0; // To reset this block
                GameConsole::PrintWarn(chosen_card->GetUsageRule());
            }
        }
    }
    while (option < 1 || option > player_hand_size);
        
    // 8 - Remove carta da mão do jogador // Player
    
    // 9 - Adiciona carta ao topo da discard // TableController
    // 10 - Checa se a carta tem um efeito imediato.
        // 9.1 - Se tem, aplica o efeito.
    // 11 - próximo turno.
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

const std::vector<std::shared_ptr<Player>>& TurnsController::GetPlayers()
{
    return this->players_;
}

const std::shared_ptr<Player>& TurnsController::GetCurrentPlayer() const
{
    return current_player;
}
