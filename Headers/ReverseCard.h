#pragma once
#include "Card.h"

class ReverseCard : public Card
{
public:
    ReverseCard(ECardColor card_color);
    void OnPlaceAction(ICardActionHandler* handler) override;
};
