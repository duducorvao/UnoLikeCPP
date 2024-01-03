#pragma once
#include <iostream>

class GameConsole
{
public:
    static void Print(const std::string& message);
    static void PrintLine(const std::string& message);
    static void PrintLine();
    static void PrintErr(const std::string& message);
    static void SetColor(const std::string& color);

    template<typename T>
    static T Read(const std::string& message = "")
    {
        T readData;
        std::cout << message;
        std::cin >> std::ws >> readData;

        return readData;
    }
};
