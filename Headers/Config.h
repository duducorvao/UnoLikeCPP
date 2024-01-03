#pragma once

class Config
{
public:
    static constexpr int PLAYERS_MIN_AMOUNT {2};
    static constexpr int PLAYERS_MAX_AMOUNT {10};
    static constexpr int PLAYERS_HAND_SIZE {7};

    static constexpr int CARDS_NUMBER_TOTAL {80};
    static constexpr int CARDS_PLUS_TWO_TOTAL {8};
    static constexpr int CARDS_REVERSE_TOTAL {8};
    static constexpr int CARDS_JUMP_TOTAL {8};
    static constexpr int CARDS_TOTAL {CARDS_NUMBER_TOTAL + CARDS_PLUS_TWO_TOTAL + CARDS_REVERSE_TOTAL + CARDS_JUMP_TOTAL};
    static constexpr int CARDS_NUMBER_AMOUNT_PER_COLOR {2};
    static constexpr int NUMBERS[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Colors
    static constexpr char CARD_BLUE_COLOR[] = "\033[94m";
    static constexpr char CARD_YELLOW_COLOR[] ="\033[93m";
    static constexpr char CARD_RED_COLOR[] = "\033[91m";
    static constexpr char CARD_GREEN_COLOR[] = "\033[92m";
    static constexpr char CONSOLE_NORMAL_COLOR[] = "\033[0m";
    static constexpr char CONSOLE_ERROR_COLOR[] = "\033[31m";

    // Card ASCII
    static constexpr size_t CARD_MIN_WIDTH {9};
    static constexpr size_t CARD_SAFE_WIDTH_SPACE {1}; // Empty space before and after the name
    static constexpr char CARD_HORIZONTAL_BORDER {'\xcd'};  // ═
    static constexpr char CARD_VERTICAL_BORDER {'\xba'};    // ║
    static constexpr char CARD_TOP_LEFT_CORNER {'\xc9'};    // ╔
    static constexpr char CARD_TOP_RIGHT_CORNER {'\xbb'};   // ╗
    static constexpr char CARD_BOT_LEFT_CORNER {'\xc8'};    // ╚
    static constexpr char CARD_BOT_RIGHT_CORNER {'\xbc'};   // ╝
    static constexpr char CARD_EMPTY_SPACE {'\xb0'};        // ░
};
