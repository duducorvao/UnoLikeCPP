#include <sstream>
#include "../Headers/GameController.h"
#include "../Headers/Config.h"
#include "../Headers/GameConsole.h"
#include "../Headers/Player.h"

void GameController::Initialize()
{
    table_controller_ = std::make_shared<TableController>();
    turns_controller_ = std::make_shared<TurnsController>(shared_from_this());
}

void GameController::Play()
{
    GameConsole::PrintLine("Welcome to the UNO Game");
    SetupGame();
    is_playing_ = true;
    GameLoop();
}

void GameController::SetupGame() const
{
    SetupCards();
    SetupPlayers();
}

void GameController::SetupCards() const
{
    table_controller_->Initialize();
    table_controller_->SetupTable();
}

void GameController::SetupPlayers() const
{
    int players_amount;
    do
    {
        std::ostringstream oss;
        oss << "Choose how many players will play (";
        oss << Config::PLAYERS_MIN_AMOUNT << " - " << Config::PLAYERS_MAX_AMOUNT << "): ";
        
        players_amount = GameConsole::Read<int>(oss.str());
    }
    while (players_amount < Config::PLAYERS_MIN_AMOUNT || players_amount > Config::PLAYERS_MAX_AMOUNT);

    std::vector<std::shared_ptr<Player>> players;
    for (int i = 0; i < players_amount; ++i)
    {
        std::ostringstream oss;
        oss << "Enter the name of the player number " << i + 1 << ": ";
        std::string name = GameConsole::Read<std::string>(oss.str());

        std::shared_ptr<Player> new_player = std::make_shared<Player>(name);
        players.emplace_back(new_player);

        new_player->SetHand(table_controller_->BuyCards(Config::PLAYERS_HAND_SIZE));
    }

    turns_controller_->Initialize(table_controller_);
    turns_controller_->SetupTurns(players);
}

void GameController::GameLoop() const
{
    while (is_playing_)
    {
        turns_controller_->PlayTurn();
        turns_controller_->NextPlayer();
    }
}

void GameController::EndGame()
{
    is_playing_ = false;
}
