﻿#pragma once
#include <memory>
#include "Card.h"

class CardFactory
{
public:
    std::shared_ptr<Card> MakeCardNumber(int number, Card::ECardColor color);
    std::shared_ptr<Card> MakeCardPlusTwo(Card::ECardColor color);
    std::shared_ptr<Card> MakeCardReverse(Card::ECardColor color);
    std::shared_ptr<Card> MakeCardJump(Card::ECardColor color);
};
