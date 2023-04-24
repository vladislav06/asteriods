//
// Created by vm on 23.6.3.
//

#ifndef ASTEROIDS_SHIP_H
#define ASTEROIDS_SHIP_H


#include "../physics/Vec2d.h"
#include "../physics/Matrix2d.h"
#include "../drawer/Drawer.h"
#include "Object.h"
#include "projectiles/Rocket.h"



//this is a main character Ship
/*-----------------> x global axis
 *
 * |      /\
 * |      || X local axis
 * |      ||
 * | y global axis
 *\/      /\
 *       /  \
 *      /    \  ------> x local axis
 *     /______\
 *    /   \/   \
 *
 */
class Ship : public Object {
public:

    enum ProjectileType {
        ROCKET,
        BULLET,
        LASER,
    };

private:

    int cooldownTime = 0;

    ProjectileType projectileType = BULLET;

public:
    Ship();


    void draw(Drawer *drawer) override;

    bool onCollision(Object &object, Vec2d direction) override;

    Projectile *shoot();

    void onTick() override;

    void setProjectileType(ProjectileType projType);

};


#endif //ASTEROIDS_SHIP_H
