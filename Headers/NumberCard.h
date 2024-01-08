#pragma once
#include "Card.h"
#include <memory>

class NumberCard : public Card
{
private:
    int number_ {0};
    
public:
    NumberCard(int number, ECardColor card_color);
    int GetNumber() const;
    bool CheckUseCondition(const std::shared_ptr<Card>& other_card) override;
    void OnPlaceAction() override;
    void OnTurnBeginAction() override;
};
