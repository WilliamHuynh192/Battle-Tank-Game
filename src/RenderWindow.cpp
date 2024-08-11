#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* title, int width, int height) :
    m_window(nullptr), m_gameSurface(nullptr) 
{

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
    else {
        m_gameSurface = SDL_GetWindowSurface( m_window );
    }

}

void RenderWindow::cleanUp() {
    //Destroy window
    SDL_DestroyWindow( m_window );

}

bool RenderWindow::loadSprites() {

    return true;
}