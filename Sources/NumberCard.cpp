#include "../Headers/NumberCard.h"

NumberCard::NumberCard(const int number, const ECardColor card_color) : number_(number)
{
    card_color_ = card_color;
    card_type_ = ECardType::Number;
}

bool NumberCard::CheckUseCondition()
{
    return false;
}

void NumberCard::OnPlaceAction()
{
    
}

void NumberCard::OnRoundBeginAction()
{
    
}
