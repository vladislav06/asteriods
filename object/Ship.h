//
// Created by vm on 23.6.3.
//

#ifndef ASTEROIDS_SHIP_H
#define ASTEROIDS_SHIP_H


#include "../physics/Vec2d.h"
#include "../physics/Matrix2d.h"
#include "../drawer/Drawer.h"



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
class Ship {
private:

    // coordinates of this Ship
    Vec2d cord;

    // local speed of this Ship
    Vec2d speed;

    // local acceleration vector of this Ship
    Vec2d acc;

    // rotational matrix to transform local coordinates to global
    Matrix2d rotation;


public:
    Ship();
    void rotateByDeg(double a);

    Vec2d getLocalAcceleration();

    void setLocalAcceleration(Vec2d acc);

    Vec2d getLocalSpeed();

    void setLocalSpeed(Vec2d speed);

    Vec2d getGlobalSpeed();

    Vec2d getCords();

    void setCords(Vec2d cord);

    void draw(Drawer *drawer);

};


#endif //ASTEROIDS_SHIP_H
