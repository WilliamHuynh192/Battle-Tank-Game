#pragma once

#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;
 
bool initSDL();

bool loadComponents();

void closeSDL();

bool loadImage(string imagePath, SDL_Surface* imageComponent);


// TODO: Maybe make these utilize smart pointers? Just need to provide custom deleter to pass to the pointer
SDL_Window* g_window = nullptr;
SDL_Surface* g_gameSurface = nullptr; // Game surface contain in the window
SDL_Surface* g_currentImageComponent = nullptr;

SDL_Surface* g_imageIdle = nullptr;
SDL_Surface* g_imageLeft = nullptr;
SDL_Surface* g_imageRight = nullptr;
SDL_Surface* g_imageUp = nullptr;
SDL_Surface* g_imageDown = nullptr;

// enum {
//     KEY_PRESSED_LEFT,
//     KEY_PRESSED_RIGHT,
//     KEY_PRESSED_UP,
//     KEY_PRESSED_DOWN,
//     TOTAL_KEY
// }

