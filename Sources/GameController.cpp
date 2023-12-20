#include "../Headers/GameController.h"

GameController::GameController()
{
    table_controller_ = std::make_unique<TableController>();
    turns_controller_ = std::make_unique<TurnsController>();
}

void GameController::Initialize()
{
}

void GameController::Play()
{
}

void GameController::SetupGame()
{
}

void GameController::SetupPlayers()
{
}

void GameController::StartGame()
{
}
