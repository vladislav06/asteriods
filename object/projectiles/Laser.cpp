//
// Created by vm on 23.26.4.
//

#include "Laser.h"
#include <typeinfo>

Laser::Laser(Vec2d pos, Matrix2d dir, Vec2d speed) : Projectile(pos, dir, Vec2d(0,0)) {
    collisionBox = CollisionBox(&coordinates, 1);
}

bool Laser::onCollision(Object &object, Vec2d direction) {
    if (typeid(object) == typeid(*this)) {
        return false;
    }    return true;
}

void Laser::draw(Drawer *drawer) {
    Color color;
    color.r = 255;

    drawer->line((transform * (Vec2d(0, -10)))+coordinates, (transform * (Vec2d(0, -200))) + coordinates, color);
}

int Laser::gunCoolDown() {
    return 300;
}

void Laser::onTick() {
    if (time > 60) {
        markedForRemoval = true;
    }
}

