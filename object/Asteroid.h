//
// Created by vm on 23.13.3.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H


#include "Object.h"

class Asteroid : public Object {
    Matrix2d scale;
    float size;

public:
    Asteroid(float size);

    void draw(Drawer *drawer) override;

    bool onCollision(Object &object, Vec2d direction) override;
    void onTick() override;

};


#endif //ASTEROIDS_ASTEROID_H
