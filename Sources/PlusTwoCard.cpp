#include "../Headers/PlusTwoCard.h"
#include "../Headers/GameConsole.h"
#include "../Headers/ICardActionHandler.h"

PlusTwoCard::PlusTwoCard(const ECardColor card_color)
{
    card_type_ = ECardType::PlusTwo;
    card_color_ = card_color;
    view_name_ = "Plus Two";
    usage_rule_ = "Plus Two cards can only match with other cards with the same color OR type.";
    
    CalculateCardSize();
}

bool PlusTwoCard::CheckPlaceCondition(const std::shared_ptr<Card>& other_card)
{
    return other_card->GetCardType() == card_type_;
}

void PlusTwoCard::OnPlaceAction(ICardActionHandler* handler)
{
    GameConsole::PrintWarn("Plus Two Card activated!!! The next player may be forced to buy cards. \n");
    GameConsole::WaitForEnterInput();
    handler->HandlePlusTwoPlaceAction();
}