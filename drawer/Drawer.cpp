//
// Created by vm on 23.6.3.
//

#include "Drawer.h"

void Drawer::init(SDL_Window *window) {
    this->renderer = SDL_CreateRenderer(window,
                                        -1,
                                        SDL_RENDERER_PRESENTVSYNC |
                                        SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Could not create renderer\n");
    }

}

void Drawer::fill(int r, int g, int b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
