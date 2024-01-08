#include "../Headers/ReverseCard.h"

ReverseCard::ReverseCard(const ECardColor card_color)
{
    card_type_ = ECardType::Reverse;
    card_color_ = card_color;
    view_name_ = "Reverse";
    usage_rule_ = "Reverse cards can only match with other cards with the same color OR type.";

    CalculateCardSize();
}

void ReverseCard::OnPlaceAction()
{
}

void ReverseCard::OnTurnBeginAction()
{
}