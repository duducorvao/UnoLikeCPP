#pragma once
#include "Card.h"

class PlusTwoCard : public Card
{
public:
    PlusTwoCard(ECardColor card_color);
    bool CheckPlaceCondition(const std::shared_ptr<Card>& other_card) override;
    void OnPlaceAction(ICardActionHandler* handler) override;
};
