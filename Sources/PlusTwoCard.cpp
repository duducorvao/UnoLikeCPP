#include "../Headers/PlusTwoCard.h"

PlusTwoCard::PlusTwoCard(const ECardColor card_color)
{
    card_type_ = ECardType::PlusTwo;
    card_color_ = card_color;
    view_name_ = "Plus Two";

    CalculateCardSize();
}

bool PlusTwoCard::CheckUseCondition()
{
    return false;
}

void PlusTwoCard::OnPlaceAction()
{
}

void PlusTwoCard::OnRoundBeginAction()
{
}
