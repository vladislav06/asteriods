//
// Created by vm on 23.18.4.
//
#include "../../physics/util.h"

#include "Smoke.h"

Smoke::Smoke(Vec2d coordinates) {
    this->coordinates = coordinates;
    collisionBox = CollisionBox(&coordinates,-1);
}


bool Smoke::onCollision(Object &object, Vec2d direction) {
    return false;
}

void Smoke::draw(Drawer *drawer) {
    drawer->circle(this->coordinates,10);
    drawer->circle(this->coordinates + getRandomVector(10),10);
    drawer->circle(this->coordinates + getRandomVector(10),10);
    drawer->circle(this->coordinates + getRandomVector(10),10);
    drawer->circle(this->coordinates + getRandomVector(10),10);
    drawer->circle(this->coordinates + getRandomVector(10),10);

}

void Smoke::onTick() {
    if (time > 120) {
        markedForRemoval = true;
    }
}
