#pragma once
#include "Card.h"

class ReverseCard : public Card
{
public:
    ReverseCard(ECardColor card_color);
    bool CheckUseCondition() override;
    void OnPlaceAction() override;
    void OnRoundBeginAction() override;
};
