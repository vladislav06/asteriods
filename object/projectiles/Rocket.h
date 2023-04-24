//
// Created by vm on 23.27.3.
//

#ifndef ASTEROIDS_ROCKET_H
#define ASTEROIDS_ROCKET_H


#include "../Object.h"
#include "Projectile.h"

class Rocket : public Projectile {
public:

    Rocket(Vec2d pos, Matrix2d dir, Vec2d speed);

    void draw(Drawer *drawer) override;

    bool onCollision(Object &object, Vec2d direction) override;

    void onTick() override;


    int gunCoolDown() override;
};


#endif //ASTEROIDS_ROCKET_H
