#pragma once
#include <iostream>

class GameConsole
{
public:
    static void Print(const std::string& message);
    static void PrintLine(const std::string& message);
    static void PrintLine();
    static void PrintErr(const std::string& message);
    static void PrintWarn(const std::string& message);
    static void SetColor(const std::string& color);
    static void WaitForEnterInput(const std::string& message);
    static void WaitForEnterInput();
    static void ClearScreen();

    template<typename T>
    static T Read(const std::string& message = "")
    {
        T readData;
        std::cout << message;
        std::cin >> std::ws >> readData;

        return readData;
    }
};
