#include "graphics.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>

void usage()
{
    printf("./nes ../rom\n");
}

const int FRAMERATE = 60;
int main( int argc, char* argv[])
{
    if(argc != 2)
    {
        usage();
        return 0;
    }
    SDL_Event e;
    bool quit = false;
    Graphics* g = new Graphics();
    g->init();

    /* Game Loop */
    while(!quit)
    {
       while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
                quit = true;
        }
       g->update();
       SDL_Delay(10);// TODO update with frame rate
    }
    g->destroy();




    return 0;
}
