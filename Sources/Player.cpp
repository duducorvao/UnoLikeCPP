#include "../Headers/Player.h"

#include "../Headers/Card.h"
#include "../Headers/Config.h"
#include "../Headers/GameConsole.h"

Player::Player(std::string name) : name_(std::move(name))
{
}

void Player::Play()
{
    
}

void Player::SetHand(const std::vector<std::shared_ptr<Card>>& cards)
{
    hand_ = cards;
}

const std::string& Player::GetName() const
{
    return name_;
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
}
