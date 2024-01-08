#pragma once
#include "CardFactory.h"
#include <memory>
#include <vector>

class TableController
{
public:
    void SetupTable();
    void CreateCards();
    void ShuffleDeck();
    void DrawFirstCard();
    void PlaceCard(const std::shared_ptr<Card>& card);
    std::vector<std::shared_ptr<Card>> BuyCards(unsigned int amount);
    std::weak_ptr<Card> GetTopCard() const;
    void PrintTopCard() const;
    
private:
    std::vector<std::shared_ptr<Card>> deck_;
    std::vector<std::shared_ptr<Card>> discard_;
    std::unique_ptr<CardFactory> card_factory_;

    void RecycleCards();
};
