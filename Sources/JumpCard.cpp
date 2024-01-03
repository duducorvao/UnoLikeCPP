#include "../Headers/JumpCard.h"

JumpCard::JumpCard(const ECardColor card_color)
{
    card_type_ = ECardType::Jump;
    card_color_ = card_color;
    view_name_ = "Jump";

    CalculateCardSize();
}

bool JumpCard::CheckUseCondition()
{
    return false;
}

void JumpCard::OnPlaceAction()
{
}

void JumpCard::OnRoundBeginAction()
{
}