#include "../Headers/GameConsole.h"

void GameConsole::Print(std::string_view message)
{
    std::cout << message;
}

void GameConsole::PrintLine(std::string_view message)
{
    Print(message);
    std::cout << '\n';
}
