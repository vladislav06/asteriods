//
// Created by vm on 23.27.3.
//

#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H


#include "Object.h"

class Bullet: public Object {
public:
    Bullet(Vec2d pos,Matrix2d dir,Vec2d speed);

    void draw(Drawer *drawer) override;

    void onCollision(std::vector<Object *> &objects, std::vector<Object *>::iterator it) override;

};


#endif //ASTEROIDS_BULLET_H
