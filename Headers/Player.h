#pragma once
#include <memory>
#include <vector>
#include <string>

class Card;

class Player
{
    
public:
    Player(std::wstring name);
    void SetHand(const std::vector<std::weak_ptr<Card>>& cards);
    std::wstring GetName() const;
    void PrintCards() const;
    
private:
    std::wstring name_;
    bool can_say_uno_ = false;
    bool has_said_uno_ = false;

    std::vector<std::weak_ptr<Card>> hand_;
};
