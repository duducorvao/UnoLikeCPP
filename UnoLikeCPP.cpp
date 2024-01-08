#include "Headers/GameController.h"

int main()
{
    const std::shared_ptr<GameController> game_controller = std::make_shared<GameController>();
    game_controller->Initialize();
    game_controller->Play();
    return 0;
}

