//
// Created by vm on 23.15.3.
//

#ifndef ASTEROIDS_COLLISIONBOX_H
#define ASTEROIDS_COLLISIONBOX_H


#include "Vec2d.h"

// object for collision detection
// actually not a box but a circle, but who cares
class CollisionBox {
private:
    float radius;
    Vec2d *coordinates;
public:
    CollisionBox(Vec2d *coordinates, float radius) :
            coordinates(coordinates), radius(radius) {};


    bool collideWith(CollisionBox &anotherBox);
};


#endif //ASTEROIDS_COLLISIONBOX_H
