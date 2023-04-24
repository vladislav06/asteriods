//
// Created by vm on 23.20.4.
//

#include "Bullet.h"
#include "../effects/Smoke.h"
#include "../../world/World.h"

bool Bullet::onCollision(Object &object, Vec2d direction) {
    World::getInstance()->getObjects()->push_back(new Smoke(this->coordinates));
    return true;
}

void Bullet::draw(Drawer *drawer) {
    drawer->ellipse(coordinates, Vec2d(2.5,5));
}

int Bullet::gunCoolDown() {
    return 20;
}

void Bullet::onTick() {

}

Bullet::Bullet(Vec2d pos, Matrix2d dir, Vec2d speed) : Projectile(pos, dir, speed + (dir * Vec2d(-40,0))) {
    collisionBox = CollisionBox(&coordinates, 2);

}
