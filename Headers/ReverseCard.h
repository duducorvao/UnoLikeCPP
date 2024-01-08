#pragma once
#include "Card.h"
#include <memory>

class ReverseCard : public Card
{
public:
    ReverseCard(ECardColor card_color);
    void OnPlaceAction() override;
    void OnTurnBeginAction() override;
};
