#include "../Headers/NumberCard.h"

#include "../Headers/Config.h"

NumberCard::NumberCard(const int number, const ECardColor card_color) : number_(number)
{
    card_color_ = card_color;
    card_type_ = ECardType::Number;
    view_name_ = std::to_string(number);

    CalculateCardSize();
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
