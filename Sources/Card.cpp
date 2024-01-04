#include <sstream>
#include "../Headers/Card.h"
#include "../Headers/Config.h"

Card::Card(ECardColor card_color, ECardType card_type) : card_color_(card_color), card_type_(card_type)
{
}

Card::ECardColor Card::GetCardColor() const
{
    return card_color_;
}

Card::ECardType Card::GetCardType() const
{
    return card_type_;
}

std::string Card::GetCardViewName()
{
    return view_name_;
}

std::string Card::GetCardTopSection() const
{
    // ╔═════════╗
    
    std::ostringstream oss;
    oss << Config::CARD_TOP_LEFT_CORNER;

    for (size_t i = 0; i < card_internal_size_; ++i)
    {
        oss << Config::CARD_HORIZONTAL_BORDER;
    }

    oss << Config::CARD_TOP_RIGHT_CORNER;
    return oss.str();
}

std::string Card::GetCardEmptySection() const
{
    // ║         ║
    
    std::ostringstream oss;
    oss << Config::CARD_VERTICAL_BORDER;

    for (size_t i = 0; i < card_internal_size_; ++i)
    {
        oss << Config::CARD_EMPTY_SPACE;
    }

    oss << Config::CARD_VERTICAL_BORDER;
    return oss.str();
}

std::string Card::GetCardNameSection() const
{
    // ║    view_name_    ║
    
    std::ostringstream oss;
    oss << Config::CARD_VERTICAL_BORDER;

    for (size_t i = 0; i < Config::CARD_SAFE_WIDTH_SPACE; ++i)
    {
        oss << Config::CARD_EMPTY_SPACE;
    }

    // card_internal_size_ is the internal size of the card, disregarding the borders
    // internal_safe_size is the size available to add the card name disregarding the safe leading and trailing empty spaces
    // internal_empty_size is the opposite of the above. Is the amount of empty spaces that will need to be filled in.
    const size_t internal_safe_size = card_internal_size_ - Config::CARD_SAFE_WIDTH_SPACE * 2;
    size_t internal_empty_size = internal_safe_size - view_name_.length();

    size_t spaces_used {0};
    for (size_t i = internal_empty_size; i > internal_empty_size / 2; --i)
    {
        // First, add the leading empty spaces and count how much it was used.
        ++spaces_used;
        oss << Config::CARD_EMPTY_SPACE;
    }

    // Update the amount of empty spaces that is left to use.
    internal_empty_size = internal_empty_size - spaces_used;

    // Add the name of the card
    oss << view_name_;

    // Use the rest of the internal empty spaces
    for (size_t i = internal_empty_size; i > 0; --i)
    {
        oss << Config::CARD_EMPTY_SPACE;
    }

    for (size_t i = 0; i < Config::CARD_SAFE_WIDTH_SPACE; ++i)
    {
        oss << Config::CARD_EMPTY_SPACE;
    }

    oss << Config::CARD_VERTICAL_BORDER;
    return oss.str();
}

std::string Card::GetCardBotSection() const
{
    // ╚═════════╝
    
    std::ostringstream oss;
    oss << Config::CARD_BOT_LEFT_CORNER;

    for (size_t i = 0; i < card_internal_size_; ++i)
    {
        oss << Config::CARD_HORIZONTAL_BORDER;
    }

    oss << Config::CARD_BOT_RIGHT_CORNER;
    return oss.str();
}

void Card::CalculateCardSize()
{
    card_internal_size_ = std::max(Config::CARD_MIN_WIDTH, view_name_.length() + (Config::CARD_SAFE_WIDTH_SPACE * 2));
}

std::string Card::GetCardViewColor() const
{
    switch (card_color_) {
    case ECardColor::Blue:
        return Config::CARD_BLUE_COLOR;
    case ECardColor::Yellow:
        return Config::CARD_YELLOW_COLOR;
    case ECardColor::Red:
        return Config::CARD_RED_COLOR;
    case ECardColor::Green:
        return  Config::CARD_GREEN_COLOR;
    }

    return Config::CONSOLE_NORMAL_COLOR;
}
