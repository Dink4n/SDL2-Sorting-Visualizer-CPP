#include "Game.hpp"

#include <time.h>

int i, j;

SDL_Rect rects[100];
int rectsLen = sizeof(rects)/sizeof(rects[0]);

void Swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void Swap(SDL_Rect& a, SDL_Rect& b)
{
    SDL_Rect tmp = a;
    a = b;
    b = tmp;
}

void GenRandomRects(SDL_Rect* rects)
{
    for(int i = 0; i < 100; ++i)
    {
       SDL_Rect tmpRect;
       tmpRect.x = 8 * i;
       tmpRect.y = rand() % 600;
       tmpRect.w = 8;
       tmpRect.h = 600 - tmpRect.y;

       rects[i] = tmpRect;
    }
}

void Game::Setup()
{
    // Intialize variables
    i = 0;
    j = 0;

    // seed random
    srand((unsigned)time(NULL));

    // create random rectangles
    GenRandomRects(rects);
}

void Game::HandleEvents()
{
    // Process Input
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            m_GameRunning = false;
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                m_GameRunning = false;

            if (event.key.keysym.sym == SDLK_r)
                GenRandomRects(rects);

            break;
    }
}

void Game::Update()
{
}

void Game::Render()
{
    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(m_Renderer);

    // Draw the rectangles
    SDL_SetRenderDrawColor(m_Renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);

    for (SDL_Rect& rect : rects)
    {
        SDL_RenderFillRect(m_Renderer, &rect);
    }

    // update the screen
    SDL_RenderPresent(m_Renderer);
}
