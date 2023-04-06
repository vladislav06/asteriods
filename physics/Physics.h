//
// Created by vm on 23.7.3.
//

#ifndef ASTEROIDS_PHYSICS_H
#define ASTEROIDS_PHYSICS_H


#include "../object/Object.h"
#include <vector>

class Physics {
    int height;
    int width;

public:

    explicit Physics( int height, int width, std::vector<Object *> &objects) :
            height(height),
            width(width),
            objects(objects){};

    std::vector<Object *> &objects;

    void loop();
};


#endif //ASTEROIDS_PHYSICS_H
