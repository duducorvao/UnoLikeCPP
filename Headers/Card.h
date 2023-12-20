#pragma once

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

    enum class ECardType
    {
        Number,
        PlusTwo,
        Reverse,
        Jump
    };

    Card() = default;
    virtual ~Card() = default;
    ECardColor GetCardColor() const;
    ECardType GetCardType() const;
    
protected:
    ECardColor card_color_ {ECardColor::Blue};
    ECardType card_type_  {ECardType::Number};

    virtual bool CheckUseCondition() = 0;
    virtual void OnPlaceAction() = 0;
    virtual void OnRoundBeginAction() = 0;
};
