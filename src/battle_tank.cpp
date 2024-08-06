#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    const int SCREEN_WIDTH = 1366;
    const int SCREEN_HEIGHT = 768;

    // Create the window instance
    SDL_Window* window = nullptr;

    //The game area contained by the window
    SDL_Surface* gameSurface = nullptr;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else {
        window = SDL_CreateWindow(
            "Battle Tank",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
        );

        if( window == nullptr ) {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else {
            gameSurface = SDL_GetWindowSurface( window );

            // Do something with the surface
            SDL_FillRect( gameSurface, NULL, SDL_MapRGB( gameSurface->format, 0xFF, 0xFF, 0xFF ) );

            SDL_UpdateWindowSurface( window );

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
