#include "../Headers/PlusTwoCard.h"

PlusTwoCard::PlusTwoCard(const ECardColor card_color)
{
    card_type_ = ECardType::PlusTwo;
    card_color_ = card_color;
    view_name_ = "Plus Two";
    usage_rule_ = "Plus Two cards can only match with other cards with the same color OR type.";
    
    CalculateCardSize();
}

void PlusTwoCard::OnPlaceAction()
{
}

void PlusTwoCard::OnTurnBeginAction()
{
}
