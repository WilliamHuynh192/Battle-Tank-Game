#include <stdio.h>
#include <string>

#include "battle_tank.hpp"

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

    if (!loadImage("resources/left.bmp", g_imageLeft)) {
        success = false;
        return success;
    }

    if (!loadImage("resources/right.bmp", g_imageRight)) {
        success = false;
        return success;
    }

    if (!loadImage("resources/up.bmp", g_imageUp)) {
        success = false;
        return success;
    }

    if (!loadImage("resources/down.bmp", g_imageDown)) {
        success = false;
        return success;
    }

    return success;
}

bool loadImage(string imagePath, SDL_Surface* imageComponent) {
    imageComponent = SDL_LoadBMP(imagePath);

    if( imageComponent == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", imagePath, SDL_GetError() );
        return false;
    } else {
        printf( "Successfully load %s", imagePath );
    }

    return true;
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

    //Main event loop
    SDL_Event e; 
    bool quit = false; 
    
    while( !quit ) { 
        while( SDL_PollEvent( &e ) ) { 
            if( e.type == SDL_QUIT ) {
                quit = true; 
            } else if (e.type == SDL_) {

            }

            //Apply the image base on the key press
            switch (e.key.keysym.sym)
            {
                case SDLK_UP:
                    g_currentImageComponent = g_imageUp;
                    break;
                
                case SDLK_DOWN:
                    g_currentImageComponent = g_imageDown;
                    break;

                case SDLK_LEFT:
                    g_currentImageComponent = g_imageLeft;
                    break;

                case SDLK_RIGHT:
                    g_currentImageComponent = g_imageRight;
                    break;
            
                default:
                    g_currentImageComponent = g_imageIdle;
                    break;
            }

            SDL_BlitSurface( g_currentImageComponent, NULL, g_gameSurface, NULL );
            
            //Update the surface
            SDL_UpdateWindowSurface( g_window );
        } 
    }


    /*
    * Free SDL resources
    */

    closeSDL();

    return 0;
}
