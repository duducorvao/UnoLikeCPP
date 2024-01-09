#pragma once
#include "Card.h"

class JumpCard : public Card
{
public:
    JumpCard(ECardColor card_color);
    void OnPlaceAction(ICardActionHandler* handler) override;
};
