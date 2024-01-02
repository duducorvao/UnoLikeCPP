#pragma once
#include <string>

class Config
{
public:
    static constexpr int PLAYERS_MIN_AMOUNT {2};
    static constexpr int PLAYERS_MAX_AMOUNT {10};
    static constexpr int PLAYERS_HAND_SIZE {7};

    static constexpr int CARDS_NORMAL_TOTAL {80};
    static constexpr int CARDS_PLUS_TWO_TOTAL {8};
    static constexpr int CARDS_REVERSE_TOTAL {8};
    static constexpr int CARDS_JUMP_TOTAL {8};
    static constexpr int CARDS_TOTAL {CARDS_NORMAL_TOTAL + CARDS_PLUS_TWO_TOTAL + CARDS_REVERSE_TOTAL + CARDS_JUMP_TOTAL};

    // Colors
    static constexpr char CARD_BLUE_COLOR[] = "\033[94m";
    static constexpr char CARD_YELLOW_COLOR[] ="\033[93m";
    static constexpr char CARD_RED_COLOR[] = "\033[91m";
    static constexpr char CARD_GREEN_COLOR[] = "\033[92m";
    static constexpr char CONSOLE_NORMAL_COLOR[] = "\033[0m";
    static constexpr char CONSOLE_ERROR_COLOR[] = "\033[31m";
};
