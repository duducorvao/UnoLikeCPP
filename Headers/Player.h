#pragma once
#include <memory>
#include <vector>
#include <string>

class Card;

class Player
{
    
public:
    Player(std::string name);
    void Play();
    void SetHand(const std::vector<std::weak_ptr<Card>>& cards);
    const std::string& GetName() const;
    void PrintCards() const;
    
private:
    std::string name_;
    bool can_say_uno_ = false;
    bool has_said_uno_ = false;

    std::vector<std::weak_ptr<Card>> hand_;
};
