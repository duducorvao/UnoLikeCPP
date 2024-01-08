#pragma once
#include <memory>
#include <vector>
#include <string>

class Card;

class Player
{
    
public:
    Player(std::string name);
    void SetHand(const std::vector<std::shared_ptr<Card>>& cards);
    void AddCardsToHand(const std::vector<std::shared_ptr<Card>>& cards);
    void RemoveCardFromHand(int card_index);
    void SetHasSaidUno(bool has_said);
    
    std::vector<std::shared_ptr<Card>> GetMatchingCards(const std::shared_ptr<Card>& card);
    std::shared_ptr<Card> GetCardAt(int index);
    const std::string& GetName() const;
    int GetHandSize() const;
    bool CanSayUno();
    bool GetHasSaidUno() const;
    void PrintHand() const;
    
private:
    std::string name_;
    bool can_say_uno_ = false;
    bool has_said_uno_ = false;

    std::vector<std::shared_ptr<Card>> hand_;
};
