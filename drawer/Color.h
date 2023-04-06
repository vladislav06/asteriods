//
// Created by vm on 23.7.3.
//

#ifndef ASTEROIDS_COLOR_H
#define ASTEROIDS_COLOR_H


#include <cstdint>

class Color {
public:
    int r, g, b, a;

    Color() : r(0), g(0), b(0), a(255) {};

    Color(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {};

    uint32_t toUint32();

};


#endif //ASTEROIDS_COLOR_H
