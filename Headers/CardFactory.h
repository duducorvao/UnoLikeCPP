#pragma once
#include <memory>
#include "Card.h"
#include "GameConsole.h"
#include "NumberCard.h"

class CardFactory
{
public:
    std::shared_ptr<Card> MakeCard(Card::ECardType type);
};
