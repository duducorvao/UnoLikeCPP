#pragma once
#include "Card.h"

class JumpCard : public Card
{
public:
    JumpCard(ECardColor card_color);
    bool CheckUseCondition() override;
    void OnPlaceAction() override;
    void OnRoundBeginAction() override;
};
