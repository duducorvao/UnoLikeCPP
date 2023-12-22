#include "../Headers/Player.h"

Player::Player(std::string name) : name_(std::move(name))
{
}

void Player::Play()
{
    
}

void Player::SetHand(const std::vector<std::weak_ptr<Card>>& cards)
{
    hand_ = cards;
}

std::string Player::GetName() const
{
    return name_;
}

void Player::PrintCards() const
{
    
}
