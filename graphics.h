int const SCREEN_WIDTH = 640;
int const SCREEN_HEIGHT = 480;

int renderMap(gameWorld *world, SDL_Renderer *renderer)
{
    // get the map
    char** worldMap = world->getMap();

    // what will be drawn
    SDL_Rect worldUnit;

    // set the unit size
    worldUnit.h = 3;
    worldUnit.w = 3;

    // the world should be centered on the screen, so it has to
    // be rendered with an offset
    int drawOffsetHorizontal = (SCREEN_WIDTH/2) - (world->getMapWidth()/2)*worldUnit.w;
    int drawOffsetVertical = (SCREEN_HEIGHT/2) - (world->getMapHeight()/2)*worldUnit.h;

    // go through the world map and draw world units accordingly
    for(int i = 0; i < world->getMapHeight(); i++)
    {
        for(int j = 0; j < world->getMapWidth(); j++)
        {
            // set the draw location
            worldUnit.x = j*worldUnit.w+drawOffsetHorizontal;
            worldUnit.y = i*worldUnit.h+drawOffsetVertical;

            // check what is in current square, render accordingly;
            switch(worldMap[i][j])
            {
            case 'X':
                // colorize every unit differently, just for testing purposes
                SDL_SetRenderDrawColor(renderer, i%255, 255-j%255, (i+j)%255, 255);
                SDL_RenderFillRect(renderer, &worldUnit);
                break;
            case '#':
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer, &worldUnit);
                break;
            }
        }
    }
}

int drawWindow(gameWorld *world)
{
    SDL_Window *gameWindow = NULL;

    SDL_Renderer *renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    gameWindow = SDL_CreateWindow( "Hello world", 50, 50,
                                   SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(gameWindow, -1, 0);

    // blank the window
    SDL_SetRenderDrawColor(renderer, 0, 0, 50, 255);
    SDL_RenderClear(renderer);

    // render the map
    renderMap(world, renderer);

    // show what's been rendered and wait 3 seconds
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);

    return 0;
}
