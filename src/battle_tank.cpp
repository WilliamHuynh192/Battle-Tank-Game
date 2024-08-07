#include <battle_tank.hpp>
#include <stdio.h>

bool initSDL() {
    
    bool success = false;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
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
            success = false;
        }
        else {
            gameSurface = SDL_GetWindowSurface( window );
            success = true;
        }
    }

    return success;
}

bool loadComponents() {
    
    bool success = false;

    return success;
}

void closeSDL() {

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();
}

int main(int argc, char* argv[]) {

    /*
    * Initialize 
    */

    if (!initSDL()) {
        printf("Initialization failed!!");
        return -1; // TODO Create a pop up box for exception
    }

    if (!loadComponents()) {
        printf("Failed to load components!");
        return -1; // TODO Create a pop up box for exception
    }

    /*
    * Render components
    */

    //Fill the surface white
    SDL_FillRect( gameSurface, NULL, SDL_MapRGB( gameSurface->format, 0xFF, 0xFF, 0xFF ) );
    
    //Update the surface
    SDL_UpdateWindowSurface( window );

    //Hack to get window to stay up
    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }


    /*
    * Free SDL resources
    */

    closeSDL();

    return 0;
}
