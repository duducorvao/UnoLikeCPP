#include "../Headers/NumberCard.h"
#include "../Headers/GameConsole.h"

NumberCard::NumberCard(const int number, const ECardColor card_color) : number_(number)
{
    card_color_ = card_color;
    card_type_ = ECardType::Number;
    view_name_ = std::to_string(number);
    usage_rule_ = "Number cards can only match with other cards with the same color OR number.";

    CalculateCardSize();
}

int NumberCard::GetNumber() const
{
    return number_;
}

bool NumberCard::CheckUseCondition(const std::shared_ptr<Card>& other_card)
{
    const bool color_match = other_card->GetCardColor() == card_color_;
    bool number_match {false};

    if (other_card->GetCardType() == card_type_)
    {
        const std::shared_ptr<NumberCard> number_card = std::dynamic_pointer_cast<NumberCard>(other_card);
        if (number_card != nullptr)
        {
            number_match = number_card->GetNumber() == number_;
        }
    }

    return color_match || number_match;
}