//
// Created by vm on 23.20.4.
//

#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H


#include "Projectile.h"

class Bullet : public Projectile {
public:
    Bullet(Vec2d pos, Matrix2d dir, Vec2d speed);

    bool onCollision(Object &object, Vec2d direction) override;

    void draw(Drawer *drawer) override;

    int gunCoolDown() override;

    void onTick() override;
};


#endif //ASTEROIDS_BULLET_H
