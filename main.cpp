#include "graphics.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;
const int NES_WIDTH = 256;
const int NES_HEIGHT = 240;
const int SCREEN_RESOLUTION = 2; // NES Screen Resolution

int main( int argc, char* argv[])
{
    Graphics* g = new Graphics();
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    if (SDL_Init( SDL_INIT_VIDEO ) < 0)
    {
        printf("SDL Could not initialize! \n");
        return 0;
    }
    window = SDL_CreateWindow("NES EMU", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        printf("SDL Window could not be created!\n");
        return 0;
    }
    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    /* Editing individual pixels */
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
            ((int*)screenSurface->pixels)[i + j*SCREEN_WIDTH] = 16711935;
    }
    SDL_UpdateWindowSurface(window);
    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
}
