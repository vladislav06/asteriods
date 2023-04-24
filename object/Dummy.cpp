//
// Created by vm on 23.27.3.
//

#include "Dummy.h"

Dummy::Dummy(float aa, float ab, float ba, float bb) {
    double matr[2][2] = {
            {aa, ab},
            {ba, bb}
    };
    this->transform.setMatrix(matr);
}

void Dummy::draw(Drawer *drawer) {

    Vec2d pos[5] = {
            Vec2d(0, 0),
            Vec2d(10, 0),
            Vec2d(10, 10),
            Vec2d(0, 10),
            Vec2d(0, 0)
    };

    for (int i = 0; i < 5; i++) {
        pos[i] = transform * pos[i];
    };

    Color color(0, 0, 0, 255);
    drawer->polygon(pos, 8, color);

}

bool Dummy::onCollision(Object &object, Vec2d direction) {
    return false;

}

void Dummy::onTick() {

}

