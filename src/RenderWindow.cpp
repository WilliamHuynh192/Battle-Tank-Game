#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* title, int width, int height) {

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

    // //Fill the surface white
    // SDL_FillRect( gameSurface, NULL, SDL_MapRGB( gameSurface->format, 0xFF, 0xFF, 0xFF ) );
}

void RenderWindow::cleanUp() {
    //Destroy window
    SDL_DestroyWindow( m_window );

    //Quit SDL subsystems
    SDL_Quit();
}

bool RenderWindow::loadSprites() {
    //Apply the image
    //SDL_BlitSurface( m_imageComponent, NULL, m_gameSurface, NULL );
    
    //Update the surface
    SDL_UpdateWindowSurface( m_window );

    return true;
}