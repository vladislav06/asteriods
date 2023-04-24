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
    /// coordinates of this object
    Vec2d coordinates;

    /// global speed of this object
    Vec2d speed;

    /// local acceleration vector of this object
    Vec2d acceleration;

    /// object transformation matrix (rotation, scale)
    Matrix2d transform;

    /// collision box for this object
    CollisionBox collisionBox;

    /// internal object timer that progresses every frame
    int time = 0;

    bool markedForRemoval = false;

public:
    Object();

    ~Object() = default;

    void rotateByDeg(double a);

    Matrix2d getTransformationMatrix();

    Vec2d getLocalAcceleration();

    void setLocalAcceleration(Vec2d acc);

    Vec2d getGlobalAcceleration();

    Vec2d getLocalSpeed();

    void setLocalSpeed(Vec2d spd);

    Vec2d getGlobalSpeed();

    void setGlobalSpeed(Vec2d spd);

    Vec2d &getCords();

    void setCords(Vec2d cord);

    CollisionBox &getCollisionBox();

    bool isMarkedForRemoval();

    /// Triggers internal timer
    void tick();


    /// Returns true if object needs to be destroyed
    virtual bool onCollision(Object &object, Vec2d direction) = 0;

    /// Draws object using drawer
    virtual void draw(Drawer *drawer) = 0;

protected:
    virtual void onTick() = 0;

};


#endif //ASTEROIDS_OBJECT_H
