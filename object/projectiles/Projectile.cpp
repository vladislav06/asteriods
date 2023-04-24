//
// Created by vm on 23.18.4.
//

#include "Projectile.h"


Projectile::Projectile(Vec2d pos, Matrix2d dir, Vec2d speed) {
    this->coordinates = pos;
    this->speed = speed;
    //compensate for different angle
    double matr[2][2] = {
            {0, -1},
            {1, 0}
    };
    transform = Matrix2d(matr) * dir;
    collisionBox = CollisionBox(&coordinates, 10);
}
