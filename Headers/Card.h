#pragma once
#include <string>

class Card
{
public:
    
    enum class ECardColor
    {
        Blue,
        Yellow,
        Red,
        Green
    };

    static constexpr ECardColor card_color_list[]
    {
        ECardColor::Blue,
        ECardColor::Yellow,
        ECardColor::Red,
        ECardColor::Green
    };

    enum class ECardType
    {
        Number,
        PlusTwo,
        Reverse,
        Jump
    };

    static constexpr ECardType card_type_list[]
    {
        ECardType::Number,
        ECardType::PlusTwo,
        ECardType::Reverse,
        ECardType::Jump
    };

    Card() = default;
    virtual ~Card() = default;
    Card(ECardColor card_color, ECardType card_type);
    ECardColor GetCardColor() const;
    ECardType GetCardType() const;

    virtual bool CheckUseCondition() = 0;
    virtual void OnPlaceAction() = 0;
    virtual void OnRoundBeginAction() = 0;

    std::string GetCardViewName();
    std::string GetCardTopSection() const;
    std::string GetCardEmptySection() const;
    std::string GetCardNameSection() const;
    std::string GetCardBotSection() const;
    void CalculateCardSize();
    
    std::string GetCardViewColor() const;
    
protected:
    ECardColor card_color_ {ECardColor::Blue};
    ECardType card_type_  {ECardType::Number};
    
    std::string view_name_;
    size_t card_internal_size_ {0};
};
