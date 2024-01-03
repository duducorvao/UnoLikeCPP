#include <algorithm>
#include <chrono>
#include <random>
#include "../Headers/TurnsController.h"
#include "../Headers/Player.h"

#define mod_arith(a, n) ((a % n) + n) % n

void TurnsController::Initialize(std::vector<std::shared_ptr<Player>> players)
{
    players_ = std::move(players);
    players_amount_ = players_.size();
}

void TurnsController::SetupTurns()
{
    ShufflePlayers();
    current_player = *players_.begin();
}

void TurnsController::PlayTurn() const
{
    current_player->Play();
}

void TurnsController::NextTurn()
{
    NextPlayer();
}

void TurnsController::NextPlayer()
{
    int direction;
    play_order_ == EPlayOrder::Clockwise ? direction = 1 : direction = -1;
    current_player_index_ = mod_arith((current_player_index_ + direction), players_amount_);
}

void TurnsController::ShufflePlayers()
{
    const unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
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
