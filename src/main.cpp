#include <iostream>
#include "picshow.hpp"

#define SDL_INIT_ERROR -1
#define LOAD_IMAGE_ERROR -2
#define IMAGE_BLIT_ERROR -3

int main() {
    SDL_Window* window = NULL;
    SDL_Surface* screen = NULL;
    SDL_Surface* picture = NULL;
    int test = 10;

    if (!init(window, screen, SDL_INIT_VIDEO)) {
        std::cerr << "Failed to initialize the program, exiting...\n"; exit(SDL_INIT_ERROR);
    }

    if (!loadImage("hello.bmp", picture)) {
        exit(LOAD_IMAGE_ERROR);
    }

    if (SDL_BlitSurface(picture, NULL, screen, NULL) < 0) {
        std::cerr << "Failed to blit the picture: " << SDL_GetError() << "\n"; exit(IMAGE_BLIT_ERROR);
    }

    SDL_UpdateWindowSurface(window);

    SDL_Event e;
    bool running { true };
    while (running) {
        SDL_WaitEvent(&e);
        switch (e.type) {
            case SDL_QUIT:
            running = false;
            break;
        }
    }

    close(window, picture);
    return 0;
}
