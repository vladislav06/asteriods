//
// Created by vm on 23.6.3.
//

#ifndef ASTEROIDS_DRAWER_H
#define ASTEROIDS_DRAWER_H


#include <SDL_render.h>

class Drawer {
private:
    SDL_Renderer *renderer;
public:
    void init(SDL_Window *window);
    void fill(int r, int g, int b);

};


#endif //ASTEROIDS_DRAWER_H
