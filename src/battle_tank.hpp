#pragma once

#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;
 
bool initSDL();

bool loadComponents();

void closeSDL();

SDL_Window* window = nullptr;
SDL_Surface* gameSurface = nullptr; // Game surface contain in the window