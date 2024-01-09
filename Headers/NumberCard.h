#pragma once
#include "Card.h"
#include <memory>

class NumberCard : public Card
{
public:
    NumberCard(int number, ECardColor card_color);
    int GetNumber() const;
    bool CheckUseCondition(const std::shared_ptr<Card>& other_card) override;

private:
    int number_ {0};
};
