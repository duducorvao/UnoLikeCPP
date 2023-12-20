#include "../Headers/Card.h"

Card::ECardColor Card::GetCardColor() const
{
    return card_color_;
}

Card::ECardType Card::GetCardType() const
{
    return card_type_;
}