//
// Created by vm on 23.6.3.
//

#ifndef ASTEROIDS_DRAWER_H
#define ASTEROIDS_DRAWER_H


#include <SDL_render.h>
#include <string>
#include "Color.h"
#include "../physics/Vec2d.h"

class Drawer {
private:
    SDL_Renderer *renderer;
    int fontsize = 11;
public:
    int getFontsize() const;

    void setFontsize(int fontsize);

public:
    void init(SDL_Window *window);
    void fill(int r, int g, int b);
    void line(int x1, int y1, int x2, int y2, Color color);
    void line(Vec2d pos1,Vec2d pos2, Color color);
    void circle(Vec2d pos, float radius);
    void ellipse(Vec2d pos, Vec2d radius);
    void polygon(Vec2d* pos,int n, Color color);
    void text( std::string txt, Vec2d pos);
    void present();


};


#endif //ASTEROIDS_DRAWER_H
