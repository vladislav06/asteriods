//
// Created by vm on 23.13.3.
//

#ifndef ASTEROIDS_OBJECT_H
#define ASTEROIDS_OBJECT_H


#include <valarray>
#include "../physics/Vec2d.h"
#include "../physics/Matrix2d.h"
#include "../drawer/Drawer.h"
#include "../physics/CollisionBox.h"
#include "vector"

class Object {
protected:
    // coordinates of this object
    Vec2d cord;

    // global speed of this object
    Vec2d speed;

    // local acceleration vector of this object
    Vec2d acc;

    // object transformation matrix (rotation, scale)
    Matrix2d transform;

    // collision box for this object
    CollisionBox collisionBox;

public:
    Object();

    void rotateByDeg(double a);

    Matrix2d getTransformationMatrix();

    Vec2d getLocalAcceleration();

    void setLocalAcceleration(Vec2d acc);

    Vec2d getGlobalAcceleration();

    Vec2d getLocalSpeed();

    void setLocalSpeed(Vec2d speed);

    Vec2d getGlobalSpeed();

    void setGlobalSpeed(Vec2d speed);

    Vec2d &getCords();

    void setCords(Vec2d cord);

    CollisionBox & getCollisionBox();

    virtual void onCollision(std::vector<Object *> &objects, std::vector<Object *>::iterator it) = 0;

    virtual void draw(Drawer *drawer) = 0;



};


#endif //ASTEROIDS_OBJECT_H
