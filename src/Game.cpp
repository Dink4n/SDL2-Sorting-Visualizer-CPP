#include <SDL2/SDL.h>

#include <iostream>
#include <time.h>

double HiresTimeInSeconds()
{
    return SDL_GetTicks() / 1000.0;
}

void Swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}


/* void bubble_sort(SDL_Renderer *renderer, int *array, int n) */
/* { */
/*     int i, j; */
/*     for (i = 1; i < n; i++) { */
/*         for (j = 0; j < n - 1; j++) { */
/*             if (array[j] > array[j + 1]) { */
/*                 Swap(&array[j], &array[j + 1]); */
/*                 /1* render(renderer, array); *1/ */
/*             } */
/*         } */
/*     } */
/* } */

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cerr << "SDL2_Init has Failed. Error: " << SDL_GetError() << std::endl;

    SDL_Window* window = SDL_CreateWindow("Sorting Visualizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool gameRunning = true;

    srand(time(NULL));

    /* Setup(); */
    SDL_Rect rectangles[100];
    for (int i = 0; i < 100; i++)
    {
        SDL_Rect rect;
        rect.x = 8 * i;
        rect.y = rand() % 600;
        rect.w = 8;
        rect.h = 600 - rect.y;

        rectangles[i] = rect;
    }

    SDL_Event event;
    while (gameRunning)
    {
        // Process Input
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    gameRunning = false;
                    break;

                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        gameRunning = false;

                    break;
            }
        }

        // Update
        Swap(rectangles[rand() % 100].x, rectangles[rand() % 50].x);
        SDL_Delay(10);

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);

        for (const SDL_Rect& rect : rectangles)
        {
            SDL_RenderFillRect(renderer, &rect);
        }
        SDL_RenderPresent(renderer);
    };

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
