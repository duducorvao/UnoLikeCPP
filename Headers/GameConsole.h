#pragma once
#include <iostream>
#include <string_view>

class GameConsole
{
public:
    static void Print(std::string_view message);
    static void PrintLine(std::string_view message);

    template<typename T>
    static T Read(std::string_view message)
    {
        T readData;
        std::cout << message;
        std::cin >> std::ws >> readData;

        return readData;
    }
};
