//
// Created by Craig MAYO on 2017/06/19.
//

#include "SDL2lib.hpp"

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *Head;
SDL_Texture *Food[4];
SDL_Texture *Segments[5];
SDL_Rect HeadPos;
SDL_Rect SegPos[5];
SDL_Rect FoodPos[4];

gameControl::gameControl(CoreGame *ref) {
    ScreenH = ref->getWindowHeight();
    ScreenW = ref->getWindowWidth();
    gameControl::coreGame = ref;

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Hello World", 10, 10, gameControl::ScreenW * 25, gameControl::ScreenH * 25, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        Exit();
    }

    Head = IMG_LoadTexture(renderer, "Hello.png");
    for (int i = 1; i < 5; i++) {
        Segments[i] = IMG_LoadTexture(renderer, "Hello.png");
    }

    for (int i = 0; i < 4; i++) {
        Food[i] = IMG_LoadTexture(renderer, "Hello.png");
    }

    HeadPos.x = ref->getPlayer()[0]->getPosition()[1];
    HeadPos.y = ref->getPlayer()[0]->getPosition()[0];
    HeadPos.w = 20;
    HeadPos.h = 20;

    for (int i = 1; i < 5; i++) {
        SegPos[i].x = ref->getPlayer()[i]->getPosition()[1];
        SegPos[i].y = ref->getPlayer()[i]->getPosition()[0];
        SegPos[i].w = 20;
        SegPos[i].h = 20;
    }

    for (int i = 0; i < 4; i++) {
        FoodPos[i].x = ref->getFood()[i]->getPosition()[1];
        FoodPos[i].y = ref->getFood()[i]->getPosition()[0];
        FoodPos[i].w = 20;
        FoodPos[i].h = 20;
    }
}

void gameControl::draw() {
    double period = 1.0 / (double)60;
    period = period * 10000;
    int milliPeriod = (int)period;
    int sleep;
    Uint32 lastTick;
    Uint32 currentTick;

    lastTick = SDL_GetTicks();

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 153, 0, 0);
    HeadPos.x = coreGame->getPlayer()[0]->getPosition()[1];
    HeadPos.y = coreGame->getPlayer()[0]->getPosition()[0];
    SDL_RenderCopy(renderer, Head, NULL, &HeadPos);
    for (int i = 1; i < 5; i++) {
        SegPos[i].x = coreGame->getPlayer()[i]->getPosition()[1];
        SegPos[i].y = coreGame->getPlayer()[i]->getPosition()[0];
        SDL_RenderCopy(renderer, Segments[i], NULL, &SegPos[i]);
    }
    for (int i = 0; i < 4; i++) {
        FoodPos[i].x = coreGame->getFood()[i]->getPosition()[1];
        FoodPos[i].y = coreGame->getFood()[i]->getPosition()[0];
        SDL_RenderCopy(renderer, Food[i], NULL, &FoodPos[i]);
    }
    SDL_RenderPresent(renderer);

    currentTick = SDL_GetTicks();
    sleep = milliPeriod - (currentTick - lastTick);
    if(sleep < 0) { sleep = 0; }
    SDL_Delay(sleep);
}

void gameControl::Exit() {
    SDL_DestroyTexture(Head);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    coreGame->setState(3);
}


void gameControl::CheckInput() {
    SDL_Event e;

    if (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_KEYUP: {
                switch (e.key.keysym.sym) {
                    case SDLK_UP: {
                        if (coreGame->getPlayer()[0]->getDirection() != DOWN)
                            coreGame->getPlayer()[0]->setDirection(UP);
                        break;
                    }
                    case SDLK_LEFT: {
                        if (coreGame->getPlayer()[0]->getDirection() != RIGHT)
                            coreGame->getPlayer()[0]->setDirection(LEFT);
                        break;
                    }
                    case SDLK_DOWN: {
                        if (coreGame->getPlayer()[0]->getDirection() != UP)
                            coreGame->getPlayer()[0]->setDirection(DOWN);
                        break;
                    }
                    case SDLK_RIGHT: {
                        if (coreGame->getPlayer()[0]->getDirection() != LEFT)
                            coreGame->getPlayer()[0]->setDirection(RIGHT);
                        break;
                    }
                    case SDLK_ESCAPE: {
                        Exit();
                    }
                    default: {
                        break;
                    }
                }
            }
            default: {
                break;
            }
        }
    }
}
void gameControl::update() {}
int gameControl::getScreenW() { return ScreenW; }
void gameControl::setScreenW(int ScreenW) { gameControl::ScreenW = ScreenW; }
int gameControl::getScreenH() { return ScreenH; }
void gameControl::setScreenH(int ScreenH) { gameControl::ScreenH = ScreenH; }
extern "C"
gameControl *create(CoreGame *ref) { return new gameControl(ref); }
extern "C"
void destroy(CoreGame *coreGame) { delete coreGame; }
CoreGame *gameControl::getCoreGame() const { return coreGame; }
void gameControl::setCoreGame(CoreGame *coreGame) { gameControl::coreGame = coreGame; }
extern "C"
void *screen(gameControl *obj) {
    obj->CheckInput();
    obj->draw();
    return (0);
};
gameControl::~gameControl() {}
