//
// Created by vm on 23.6.3.
//
#include <SDL_ttf.h>
#include <SDL2_gfxPrimitives.h>
#include "Drawer.h"
#include "text/Font.h"


FC_Font *font;

void Drawer::init(SDL_Window *window) {
    this->renderer = SDL_CreateRenderer(window,
                                        -1,
                                        SDL_RENDERER_PRESENTVSYNC |
                                        SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Could not create renderer\n");
    }
    font = FC_CreateFont();
    FC_LoadFont(font, renderer, "/home/vm/Documents/asteroids/cmake-build-debug/Sans.ttf", 50, FC_MakeColor(255,0,0,255), TTF_STYLE_NORMAL);


}

void Drawer::fill(int r, int g, int b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderClear(renderer);
}

void Drawer::line(int x1, int y1, int x2, int y2, Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);


}

void Drawer::line(Vec2d pos1, Vec2d pos2, Color color) {
    line(pos1.x, pos1.y, pos2.x, pos2.y, color);
}

void Drawer::present() {
    SDL_RenderPresent(renderer);
}

void Drawer::circle(Vec2d pos, float radius) {


    Color color(255, 0, 0, 128);
    circleColor(renderer, pos.x, pos.y, radius, color.toUint32());
}

void Drawer::polygon(Vec2d *pos, int n, Color color) {

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);

    for (int i = 0; i < n - 1; i++) {
        SDL_RenderDrawLine(renderer,
                           pos[i].x,
                           pos[i].y,
                           pos[i + 1].x,
                           pos[i + 1].y);

    }

}

void Drawer::text(std::string txt, Vec2d pos) {


    //this opens a font style and sets a size
    FC_Draw(font, renderer, pos.x, pos.y, txt.c_str());

}

void Drawer::ellipse(Vec2d pos, Vec2d radius) {
    ellipseRGBA(renderer,pos.x,pos.y,radius.x,radius.y,0,0,0,255);
}



