//
// Created by vm on 23.7.3.
//

#ifndef ASTEROIDS_PHYSICS_H
#define ASTEROIDS_PHYSICS_H


#include "../object/Object.h"
#include <vector>
#include <list>

class Physics {
    int height;
    int width;

public:

    explicit Physics( int height, int width) :
            height(height),
            width(width){};


    void loop();
};


#endif //ASTEROIDS_PHYSICS_H
