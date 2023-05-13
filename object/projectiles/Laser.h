//
// Created by vm on 23.26.4.
//

#ifndef ASTEROIDS_LASER_H
#define ASTEROIDS_LASER_H


#include "Projectile.h"

class Laser : public Projectile{
public:
    Laser(Vec2d pos, Matrix2d dir, Vec2d speed);


    bool onCollision(Object &object, Vec2d direction) override;

    void draw(Drawer *drawer) override;

    int gunCoolDown() override;

protected:
    void onTick() override;
};


#endif //ASTEROIDS_LASER_H
