#include "Game.hpp"

Game::Game()
    : m_Window(NULL), m_Renderer(NULL), m_GameRunning(false)
{}

void Game::Init(const char* title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cerr << "SDL2_Init has Failed. Error: " << SDL_GetError() << std::endl;

    m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (!m_Window)
        std::cerr << "SDL2 cannot create the window. Error: " << SDL_GetError() << std::endl;

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!m_Renderer)
        std::cerr << "SDL2 cannot create the renderer. Error: " << SDL_GetError() << std::endl;

    m_GameRunning = true;
}

void Game::CleanUp()
{
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}

bool Game::IsRunning()
{
    return m_GameRunning;
}
