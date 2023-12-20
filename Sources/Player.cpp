#include "../Headers/Player.h"

Player::Player(std::wstring name) : name_(std::move(name))
{
}

void Player::SetHand(const std::vector<std::weak_ptr<Card>>& cards)
{
    hand_ = cards;
}

std::wstring Player::GetName() const
{
    return name_;
}

void Player::PrintCards() const
{
    
}
