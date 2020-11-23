#include "Game.hpp"

Game* game;

void Init()
{
    game = new Game();
    game->Init("Sorting Visualizer", 800, 600);
}

int main()
{
    Init();

    game->Setup();

    while (game->IsRunning())
    {
        game->HandleEvents();

        game->Update();
        /* game->Render(); */
    }


    game->CleanUp();

    delete game;

    return 0;
}
