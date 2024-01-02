#pragma once
#include "Card.h"

class PlusTwoCard : public Card
{
public:
    PlusTwoCard(ECardColor card_color);
    bool CheckUseCondition() override;
    void OnPlaceAction() override;
    void OnRoundBeginAction() override;
};
