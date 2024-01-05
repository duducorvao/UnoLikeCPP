#include "../Headers/Player.h"
#include "../Headers/Card.h"
#include "../Headers/Config.h"
#include "../Headers/GameConsole.h"

#include <sstream>

Player::Player(std::string name) : name_(std::move(name))
{
}

void Player::SetHand(const std::vector<std::shared_ptr<Card>>& cards)
{
    hand_ = cards;
}

void Player::AddCardsToHand(const std::vector<std::shared_ptr<Card>>& cards)
{
    hand_.insert(hand_.end(), cards.begin(), cards.end());
    has_said_uno_ = false;
}

void Player::RemoveCardFromHand(int card_index)
{
    const int hand_size = static_cast<int>(hand_.size());
    if (card_index < 0 || card_index > hand_size)
    {
        GameConsole::PrintErr("Tried to remove a card from the player's hand with an out of bounds index (" + std::to_string(card_index) + ").");
        return;
    }
    
    hand_.erase(hand_.begin() + card_index);
}

void Player::SetHasSaidUno(bool has_said)
{
    has_said_uno_ = has_said;
}

const std::string& Player::GetName() const
{
    return name_;
}

int Player::GetHandSize() const
{
    return static_cast<int>(hand_.size());
}

bool Player::CanSayUno()
{
    can_say_uno_ = GetHandSize() == Config::PLAYERS_HAND_SIZE_TO_SAY_UNO;
    return can_say_uno_;
}

bool Player::GetHasSaidUno() const
{
    return has_said_uno_;
}

void Player::PrintHand() const
{
    for (const auto& element : hand_)
    {
        GameConsole::SetColor(element->GetCardViewColor());
        GameConsole::Print(element->GetCardTopSection());
    }
    GameConsole::PrintLine();

    for (const auto& element : hand_)
    {
        GameConsole::SetColor(element->GetCardViewColor());
        GameConsole::Print(element->GetCardEmptySection());
    }
    GameConsole::PrintLine();
    
    for (const auto& element : hand_)
    {
        GameConsole::SetColor(element->GetCardViewColor());
        GameConsole::Print(element->GetCardNameSection());
    }
    GameConsole::PrintLine();
    
    for (const auto& element : hand_)
    {
        GameConsole::SetColor(element->GetCardViewColor());
        GameConsole::Print(element->GetCardEmptySection());
    }
    GameConsole::PrintLine();

    for (const auto& element : hand_)
    {
        GameConsole::SetColor(element->GetCardViewColor());
        GameConsole::Print(element->GetCardBotSection());
    }
    GameConsole::PrintLine();
    
    GameConsole::SetColor(Config::CONSOLE_NORMAL_COLOR);

    // Printing index options
    int index {1};
    for (const auto& element : hand_)
    {
        GameConsole::Print(element->GetCardIndexOptionSection(index));
        ++index;
    }
    GameConsole::PrintLine();
}

std::vector<std::shared_ptr<Card>> Player::GetMatchingCards(const std::shared_ptr<Card>& card)
{
    std::vector<std::shared_ptr<Card>> matching_cards;

    for (const auto& hand_card : hand_)
    {
        if (card->CheckUseCondition(hand_card))
        {
            matching_cards.emplace_back(hand_card);
        }
    }

    return matching_cards;
}

std::shared_ptr<Card> Player::GetCardAt(int index)
{
    return hand_.at(index);
}
