#include "../Headers/Card.h"

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