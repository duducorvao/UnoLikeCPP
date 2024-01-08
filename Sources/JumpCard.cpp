#include "../Headers/JumpCard.h"

JumpCard::JumpCard(const ECardColor card_color)
{
    card_type_ = ECardType::Jump;
    card_color_ = card_color;
    view_name_ = "Jump";
    usage_rule_ = "Jump cards can only match with other cards with the same color OR type.";

    CalculateCardSize();
}

void JumpCard::OnPlaceAction()
{
}

void JumpCard::OnTurnBeginAction()
{
}