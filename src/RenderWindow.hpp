#ifndef RENDER_WINDOW_HEADER
#define RENDER_WINDOW_HEADER

#include <stdio.h>
#include <SDL2/SDL.h>

class RenderWindow {

public:

    RenderWindow(const char* title, int width, int height);

    void cleanUp();

    bool loadSprites();

private:

    // TODO: Maybe make these utilize smart pointers? Just need to provide custom deleter to pass to the pointer
    SDL_Window* m_window = nullptr;
    SDL_Surface* m_gameSurface = nullptr; // Game surface contains in the window

};

#endif  // RENDER_WINDOW_HEADER