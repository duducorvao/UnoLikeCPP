#pragma once
#include "Card.h"

class NumberCard : public Card
{
public:
    bool CheckUseCondition() override;
    void OnPlaceAction() override;
    void OnRoundBeginAction() override;
};
