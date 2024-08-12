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

SDL_Texture* RenderWindow::loadTexture(const char* filePath) {

    SDL_Texture* sprite = nullptr;

    sprite = IMG_LoadTexture(m_renderer, filePath);

    if (!sprite) {
        printf("Could not load the texture from %s, error: %s", filePath, IMG_GetError());
        return nullptr;
    }

    return sprite;
}


/*
 * This function will copy the texture into the off-screen texture to prepare for rendering 
 */
int RenderWindow::render(SDL_Texture* texture) {
    return SDL_RenderCopy(m_renderer, texture, NULL, NULL);
}

void RenderWindow::display() {
    SDL_RenderPresent(m_renderer);
}