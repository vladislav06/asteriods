//

#include "Asteroid.h"
#include <SDL2_gfxPrimitives.h>

//
// Created by vm on 23.13.3.
Asteroid::Asteroid(float size) {
    double matr[2][2] = {
            {0,    size},
            {size, 0}
    };
    this->transform.setMatrix(matr);


    this->collisionBox = CollisionBox(&this->cord, 15*size);
}

void Asteroid::draw(Drawer *drawer) {
    Vec2d pos[8] = {
            Vec2d(-10, -2),
            Vec2d(-22, -1),
            Vec2d(-8, 13),
            Vec2d(2, 5),
            Vec2d(17, 1),
            Vec2d(15, -11),
            Vec2d(-3, -14),
            Vec2d(-10, -2)
    };

    for (int i = 0; i < 8; i++) {
        pos[i] = transform * pos[i];
        pos[i] = pos[i] + cord;
    };

    Color color(0, 0, 0, 255);
    drawer->polygon(pos, 8, color);
}

void Asteroid::onCollision(std::vector<Object *> &objects, std::vector<Object *>::iterator it) {


}
