#include "graphics.hpp"


/* Return 0 on success */
int Graphics::init()
{

    gwindow = NULL;
    if (SDL_Init( SDL_INIT_VIDEO ) < 0)
    {
        printf("SDL Could not initialize! \n");
        return -1;
    }
    gwindow = SDL_CreateWindow("NES EMU", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(gwindow == NULL)
    {
        printf("SDL Window could not be created!\n");
        return -1;
    }
    screenSurface = SDL_GetWindowSurface(gwindow);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    /* Clear Screen */
    for(int i = 0; i < NES_WIDTH * NES_HEIGHT; i++)
    {
        pixels[i] = 0;
    }


}
void Graphics::destroy()
{
    SDL_DestroyWindow(gwindow);
    SDL_Quit();
}

void Graphics::setPixel(int x, int y, int c)
{
    pixels[x + y*NES_WIDTH] = c;
    int screen_x = x * screen_resolution;
    int screen_y = y * screen_resolution;
    for(int i = 0; i < screen_resolution; i++)
    {
        for(int j = 0; j < screen_resolution; j++)
        {

            ((int*)screenSurface->pixels)[screen_x + i + (j + screen_y)*SCREEN_WIDTH] = c;
        }
    }
}

int Graphics::getPixel(int x, int y)
{
}
void Graphics::update()
{
    SDL_UpdateWindowSurface(gwindow);
}
