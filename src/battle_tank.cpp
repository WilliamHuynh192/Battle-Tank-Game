#include "RenderWindow.hpp"

int main(int argc, char* argv[]) {

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return -1;
    }

    RenderWindow window{"Battle Tank", 1366, 768};

    SDL_Texture* playerTank = window.loadTexture("textures/PlayerTank.png");

    if (!playerTank) {
        printf("Error loading texture! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    if (window.render(playerTank) != 0) {
        printf("Error rendering texture! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Game loop
    SDL_Event e; 
    bool quit = false; 
    while( quit == false ) { 
        while( SDL_PollEvent( &e ) ) { 
            if( e.type == SDL_QUIT ) quit = true; 
        }

        // Update the game display aera
        window.display();
    }

    window.cleanUp();
    
    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
