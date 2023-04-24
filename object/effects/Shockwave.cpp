//
// Created by vm on 23.24.4.
//

#include "Shockwave.h"
#include "../../physics/util.h"
#include <typeinfo>


Shockwave::Shockwave(Vec2d coordinates) {
    this->coordinates = coordinates;
    collisionBox = CollisionBox(&this->coordinates, 20);
}

void Shockwave::draw(Drawer *drawer) {
    for (int i = 0; i < 5; i++) {
        drawer->circle(this->coordinates + getRandomVector(10), ((time + getRandomInt(5)) % 10) * 2);
    }


}

bool Shockwave::onCollision(Object &object, Vec2d direction) {
    return false;
}

void Shockwave::onTick() {
    if (time > 60) {
        markedForRemoval = true;
    }
}
