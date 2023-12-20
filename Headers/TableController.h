﻿#pragma once
#include <memory>
#include <vector>

#include "CardFactory.h"

class TableController
{
private:
    std::vector<std::weak_ptr<Card>> deck_;
    std::vector<std::weak_ptr<Card>> discard_;
    std::unique_ptr<CardFactory> card_factory_;
    std::vector<std::shared_ptr<Card>> card_pool_;
    
public:
    void Initialize();
    void SetupTable();
    void CreateCards();
    void ShuffleDeck();
    std::vector<std::shared_ptr<Card>> BuyCards(unsigned int amount);
};
