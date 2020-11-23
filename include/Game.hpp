#pragma once
#include <SDL2/SDL.h>

#include <iostream>

class Game
{
    public:
        Game();
        void Init(const char* title, int width, int height);
        void CleanUp();

        void Setup();
        void HandleEvents();
        void Update();
        void Render();

        bool IsRunning();

    private:
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;

        bool m_GameRunning;
};
