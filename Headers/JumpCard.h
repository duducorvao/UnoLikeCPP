#pragma once
#include "Card.h"
#include <memory>

class JumpCard : public Card
{
public:
    JumpCard(ECardColor card_color);
    void OnPlaceAction() override;
    void OnTurnBeginAction() override;
};
