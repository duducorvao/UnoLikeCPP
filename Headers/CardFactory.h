#pragma once
#include <memory>

#include "Card.h"

class CardFactory
{
public:
    std::shared_ptr<Card> MakeCard(Card::ECardType type);
};
