#include "../Headers/GameConsole.h"
#include "../Headers/Config.h"
#include <limits>

void GameConsole::Print(const std::string& message)
{
    std::cout << message;
}

void GameConsole::PrintLine(const std::string& message)
{
    Print(message);
    std::cout << '\n';
}

void GameConsole::PrintLine()
{
    std::cout << '\n';
}

void GameConsole::PrintErr(const std::string& message)
{
    SetColor(Config::CONSOLE_ERROR_COLOR);
    std::cout << message << '\n';
    SetColor(Config::CONSOLE_NORMAL_COLOR);
}

void GameConsole::PrintWarn(const std::string& message)
{
    SetColor(Config::CONSOLE_WARNING_COLOR);
    std::cout << message << '\n';
    SetColor(Config::CONSOLE_NORMAL_COLOR);
}

void GameConsole::SetColor(const std::string& color)
{
    std::cout << color;
}

void GameConsole::ClearScreen()
{
#if defined _WIN32
    system("cls"); // Not very safe
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#endif
}

void GameConsole::WaitForEnterInput(const std::string& message)
{
    std::cout << message;
    std::cin.clear();
    std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    std::cin.get();
}

void GameConsole::WaitForEnterInput()
{
    WaitForEnterInput("Press ENTER to continue...");
}
