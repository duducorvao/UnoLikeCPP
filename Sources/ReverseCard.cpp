#include "../Headers/ReverseCard.h"

ReverseCard::ReverseCard(const ECardColor card_color)
{
    card_type_ = ECardType::Reverse;
    card_color_ = card_color;
}

bool ReverseCard::CheckUseCondition()
{
    return false;
}

void ReverseCard::OnPlaceAction()
{
}

void ReverseCard::OnRoundBeginAction()
{
}
