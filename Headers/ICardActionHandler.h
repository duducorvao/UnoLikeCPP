#pragma once

class ICardActionHandler
{
public:
    virtual ~ICardActionHandler() = default;
    virtual void HandleReverseCardPlaceAction() = 0;
    virtual void HandleJumpCardPlaceAction() = 0;
    virtual void HandlePlusTwoPlaceAction() = 0;
};
