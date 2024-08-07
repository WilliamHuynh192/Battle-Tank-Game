#include <battle_tank.hpp>
#include <stdio.h>

bool initSDL() {
    
    bool success = false;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else {
        g_window = SDL_CreateWindow(
            "Battle Tank",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
        );

        if( g_window == nullptr ) {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else {
            g_gameSurface = SDL_GetWindowSurface( g_window );
            success = true;
        }
    }

    return success;
}

bool loadComponents() {
    
    bool success = true;

    g_imageComponent = SDL_LoadBMP("hello_world.bmp");

    if( g_imageComponent == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}

void closeSDL() {

    //Destroy window
    SDL_DestroyWindow( g_window );

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

    // //Fill the surface white
    // SDL_FillRect( gameSurface, NULL, SDL_MapRGB( gameSurface->format, 0xFF, 0xFF, 0xFF ) );

    //Apply the image
    SDL_BlitSurface( g_imageComponent, NULL, g_gameSurface, NULL );
    
    //Update the surface
    SDL_UpdateWindowSurface( g_window );

    //Hack to get window to stay up
    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }


    /*
    * Free SDL resources
    */

    closeSDL();

    return 0;
}
