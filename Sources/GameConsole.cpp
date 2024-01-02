#include "../Headers/GameConsole.h"
#include "../Headers/Config.h"

void GameConsole::Print(const std::string& message)
{
    std::cout << message;
}

void GameConsole::PrintLine(const std::string& message)
{
    Print(message);
    std::cout << '\n';
}

void GameConsole::PrintErr(const std::string& message)
{
    SetColor(Config::CONSOLE_ERROR_COLOR);
    std::cout << message << '\n';
    SetColor(Config::CONSOLE_NORMAL_COLOR);
}

void GameConsole::SetColor(const std::string& color)
{
    std::cout << color;
}
