//
// Created by vm on 23.6.3.
//

#ifndef ASTEROIDS_SHIP_H
#define ASTEROIDS_SHIP_H


#include "../physics/Vec2d.h"
#include "../physics/Matrix2d.h"
#include "../drawer/Drawer.h"
#include "Object.h"
#include "Bullet.h"



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
private:


public:
    Ship();

    void draw(Drawer *drawer) override;

    void onCollision(std::vector<Object *> &objects, std::vector<Object *>::iterator it) override;

    Bullet *shoot();

};


#endif //ASTEROIDS_SHIP_H
