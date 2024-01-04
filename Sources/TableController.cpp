#include "../Headers/TableController.h"
#include "../Headers/Config.h"
#include <algorithm>
#include <chrono>
#include <random>

#include "../Headers/GameConsole.h"

void TableController::Initialize()
{
    //Stub method for possible later use
}

void TableController::SetupTable()
{
    CreateCards();
    CreateDeck();
    ShuffleDeck();
    DrawFirstCard();
}

void TableController::CreateCards()
{
    for (const Card::ECardColor element : Card::card_color_list)
    {
        for (const int i : Config::NUMBERS)
        {
            for (int j = 0; j < Config::CARDS_NUMBER_AMOUNT_PER_COLOR; ++j)
            {
                card_pool_.emplace_back(card_factory_->MakeCardNumber(i, element));
            }
        }

        for (int j = 0; j < Config::CARDS_NUMBER_AMOUNT_PER_COLOR; ++j)
        {
            card_pool_.emplace_back(card_factory_->MakeCardPlusTwo(element));
            card_pool_.emplace_back(card_factory_->MakeCardReverse(element));
            card_pool_.emplace_back(card_factory_->MakeCardJump(element));
        }        
    }
}

void TableController::CreateDeck()
{
    deck_ = card_pool_;
}

void TableController::ShuffleDeck()
{
    const unsigned seed = static_cast<const unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(deck_.begin(), deck_.end(), std::default_random_engine(seed));
}

void TableController::DrawFirstCard()
{
    discard_.insert(discard_.begin(), deck_.front());
    deck_.erase(deck_.begin());
}

std::vector<std::shared_ptr<Card>> TableController::BuyCards(unsigned int amount)
{
    if (amount > deck_.size())
    {
        RecycleCards();
    }

    std::vector<std::shared_ptr<Card>> draw_cards;
    draw_cards.reserve(amount);
    
    for (int i = 0; i < amount; ++i)
    {
        draw_cards.emplace_back(deck_.front());
        deck_.erase(deck_.begin());
    }
    
    return draw_cards;
}

void TableController::RecycleCards()
{
    const std::shared_ptr<Card> top_card = discard_.front();
    discard_.erase(discard_.begin());
    deck_ = std::move(discard_);
    ShuffleDeck();

    deck_.insert(deck_.begin(), top_card);
}

std::weak_ptr<Card> TableController::GetTopCard() const
{
    return discard_.front();
}

void TableController::PrintTopCard() const
{
    GameConsole::PrintLine("This is the current top card:");
    GameConsole::Print(discard_.front()->GetFullCardImage());
}
