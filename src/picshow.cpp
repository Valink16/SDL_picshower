#include "picshow.hpp"
#include <iostream>

const int SCREEN_WIDTH { 600 };
const int SCREEN_HEIGHT { 400 };

bool init(SDL_Window*& window, SDL_Surface*& screen, Uint32 init_flags) {
    if (SDL_Init(init_flags) != 0) {
        std::cerr << "Could not init SDL: " << SDL_GetError() << "\n"; return false;
    }
        
    window = SDL_CreateWindow("Picture shower", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        std::cerr << "Could not create SDL window: " << SDL_GetError() << "\n"; return false;
    }
    
    screen = SDL_GetWindowSurface(window);
    if (screen == NULL) {
        std::cerr << "Could not get screen SDL_Surface from window: " << SDL_GetError() << "\n"; return false;
    }
    
    return true;
}

bool loadImage(const std::string& filename, SDL_Surface*& image) {
    image = SDL_LoadBMP(filename.c_str());
    if (image == NULL) {
        std::cerr << "Could not load " << filename << " : " << SDL_GetError() << "\n"; return false; 
    }

    return true;
}

void close(SDL_Window* window, SDL_Surface* image) {
    SDL_FreeSurface(image);
    SDL_DestroyWindow(window);
    SDL_Quit();
}