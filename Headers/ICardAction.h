#pragma once

class ICardActionHandler;
class ICardAction
{
public:
    virtual ~ICardAction() = default;
    virtual void OnPlaceAction(ICardActionHandler* handler) = 0;
};
