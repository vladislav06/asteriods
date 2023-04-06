//
// Created by vm on 23.13.3.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H


#include "Object.h"

class Asteroid : public Object {
    Matrix2d scale;

public:
    Asteroid(float size);

    void draw(Drawer *drawer) override;

    void onCollision(std::vector<Object *> &objects, std::vector<Object *>::iterator it) override;

};


#endif //ASTEROIDS_ASTEROID_H
