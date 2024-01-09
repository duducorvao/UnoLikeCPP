#include "../Headers/JumpCard.h"
#include "../Headers/GameConsole.h"
#include "../Headers/ICardActionHandler.h"

JumpCard::JumpCard(const ECardColor card_color)
{
    card_type_ = ECardType::Jump;
    card_color_ = card_color;
    view_name_ = "Jump";
    usage_rule_ = "Jump cards can only match with other cards with the same color OR type.";

    CalculateCardSize();
}

void JumpCard::OnPlaceAction(ICardActionHandler* handler)
{
    GameConsole::PrintWarn("Jump Card activated!!! The next player will be skipped. \n");
    GameConsole::WaitForEnterInput();
    handler->HandleJumpCardPlaceAction();
}