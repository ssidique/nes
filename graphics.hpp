#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <SDL2/SDL.h>
#include <stdio.h>

class Graphics
{
    private:
    static const int SCREEN_HEIGHT = 480;
    static const int SCREEN_WIDTH = 512;
    static const int NES_WIDTH = 256;
    static const int NES_HEIGHT = 240;
    int screen_resolution = 2; // NES Screen Resolution
    int pixels[NES_WIDTH * NES_HEIGHT];
    SDL_Window* gwindow;
    SDL_Surface* screenSurface;

    public:
    int init();
    void destroy();
    void setPixel(int x, int y, int c); // TODO load NES palette
    int getPixel(int x, int y); // TODO load NES palette
    void update();
};

#endif
