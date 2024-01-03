#include "../Headers/CardFactory.h"
#include "../Headers/NumberCard.h"
#include "../Headers/JumpCard.h"
#include "../Headers/PlusTwoCard.h"
#include "../Headers/ReverseCard.h"

std::shared_ptr<Card> CardFactory::MakeCardNumber(int number, Card::ECardColor color)
{
    return std::make_shared<NumberCard>(number, color);
}

std::shared_ptr<Card> CardFactory::MakeCardPlusTwo(Card::ECardColor color)
{
    return std::make_shared<PlusTwoCard>(color);
}

std::shared_ptr<Card> CardFactory::MakeCardReverse(Card::ECardColor color)
{
    return std::make_shared<ReverseCard>(color);
}

std::shared_ptr<Card> CardFactory::MakeCardJump(Card::ECardColor color)
{
    return std::make_shared<JumpCard>(color);
}
