#include "../Headers/CardFactory.h"
#include "../Headers/NumberCard.h"

std::shared_ptr<Card> CardFactory::MakeCard(Card::ECardType type)
{
    switch (type) {
    case Card::ECardType::Number:
        return std::make_shared<NumberCard>();
    case Card::ECardType::PlusTwo:
        return std::make_shared<NumberCard>();
    case Card::ECardType::Reverse:
        return std::make_shared<NumberCard>();
    case Card::ECardType::Jump:
        return std::make_shared<NumberCard>();
    }
}
