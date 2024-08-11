#pragma once

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow {

public:

    RenderWindow(const char* title, int width, int height);

    void cleanUp();

    bool loadSprites(const char* fileName, const char* filePath);

private:

    // TODO: Maybe make these utilize smart pointers? Just need to provide custom deleter to pass to the pointer
    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
};