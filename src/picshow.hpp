#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h> 
#include <string>

// Inits all needed SDL components, program should be stopped if false
bool init(SDL_Window*& window, SDL_Surface*& screen, Uint32 init_flags);

// Loads an image
bool loadImage(const std::string& filename, SDL_Surface*& image);

// Shuts down the program
void close(SDL_Window* window, SDL_Surface* image);