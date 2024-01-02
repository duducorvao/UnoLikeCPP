﻿#pragma once
#include "Card.h"

class NumberCard : public Card
{
private:
    int number_ {0};
    
public:
    NumberCard(int number, ECardColor card_color);
    bool CheckUseCondition() override;
    void OnPlaceAction() override;
    void OnRoundBeginAction() override;
};
