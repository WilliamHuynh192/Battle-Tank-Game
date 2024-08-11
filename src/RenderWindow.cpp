#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* title, int width, int height) :
    m_window(nullptr), m_renderer(nullptr) 
{

    // Create the window
    m_window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if( m_window == nullptr ) {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() ); // TODO Create a pop up box for exception
    }

    // Create the renderer for the window, with hardware accel
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

}

void RenderWindow::cleanUp() {
    //Destroy window
    SDL_DestroyWindow( m_window );

}

bool RenderWindow::loadSprites(const char* fileName, const char* filePath) {


    return true;
}