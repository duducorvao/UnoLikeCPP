#pragma once
#include "CardFactory.h"
#include <memory>
#include <vector>

class TableController
{
private:
    std::vector<std::shared_ptr<Card>> deck_;
    std::vector<std::shared_ptr<Card>> discard_;
    std::unique_ptr<CardFactory> card_factory_;
    std::vector<std::shared_ptr<Card>> card_pool_;

    void RecycleCards();
    
public:
    void Initialize();
    void SetupTable();
    void CreateCards();
    void CreateDeck();
    void ShuffleDeck();
    void DrawFirstCard();
    std::vector<std::shared_ptr<Card>> BuyCards(unsigned int amount);
    std::weak_ptr<Card> GetTopCard() const;
    void PrintTopCard() const;

    //IsValidCardToPlay
    //GetTopCard
};
