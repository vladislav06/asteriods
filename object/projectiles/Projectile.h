//
// Created by vm on 23.18.4.
//

#ifndef ASTEROIDS_PROJECTILE_H
#define ASTEROIDS_PROJECTILE_H


#include "../Object.h"

class Projectile : public Object {
public:
    Projectile(Vec2d pos, Matrix2d dir, Vec2d speed);

    ///  virtual Projectile* instance() = 0;

    virtual int gunCoolDown() = 0;

};


#endif //ASTEROIDS_PROJECTILE_H
