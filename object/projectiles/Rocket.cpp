//
// Created by vm on 23.27.3.
//

#include "Rocket.h"
#include "../../world/World.h"
#include "../effects/Smoke.h"
#include "../effects/Shockwave.h"
#include <cmath>

# define M_PI  3.14159265358979323846

Rocket::Rocket(Vec2d pos, Matrix2d dir, Vec2d speed) : Projectile(pos, dir, speed) {

}

void Rocket::draw(Drawer *drawer) {

    Vec2d pos[] = {
            Vec2d(2, 17),
            Vec2d(12, 17),
            Vec2d(13, 16),
            Vec2d(10, 13),
            Vec2d(10, 17),
            Vec2d(10, 4),
            Vec2d(7, 1),
            Vec2d(4, 4),
            Vec2d(4, 17),
            Vec2d(4, 13),
            Vec2d(1, 16),
            Vec2d(2, 17),
    };

    //rotate and
    //move model a bit
    for (int i = 0; i < 11; i++) {
        pos[i] += Vec2d(-7, -10);
        pos[i] = transform * pos[i];
        pos[i] = pos[i] + coordinates;
    }

    Color color(0, 0, 0, 255);
    drawer->polygon(pos, 11, color);

}

bool Rocket::onCollision(Object &object, Vec2d direction) {
    World::getInstance()->getObjects()->push_back(new Shockwave(this->coordinates));
    return true;
}

void Rocket::onTick() {

}

int Rocket::gunCoolDown() {
    return 60;
}

//Projectile* Rocket::instance() {
//    return new Rocket();
//}
