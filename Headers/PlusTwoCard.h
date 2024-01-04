#pragma once
#include "Card.h"
#include <memory>

class PlusTwoCard : public Card
{
public:
    PlusTwoCard(ECardColor card_color);
    void OnPlaceAction() override;
    void OnTurnBeginAction() override;
};
