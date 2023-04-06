//
// Created by vm on 23.27.3.
//

#include "Bullet.h"
#include <cmath>

# define M_PI  3.14159265358979323846

Bullet::Bullet(Vec2d pos, Matrix2d dir, Vec2d speed) {
    this->cord = pos;
    this->speed = speed;
    //compensate for different angle
    double matr[2][2] = {
            {0, -1},
            {1, 0}
    };
    transform = Matrix2d(matr) * dir;
}

void Bullet::draw(Drawer *drawer) {

    Vec2d pos[] = {
            Vec2d(2, 17),
            Vec2d(12, 17),
            Vec2d(13, 16),
            Vec2d(10, 13),
            Vec2d(10, 17),
            Vec2d(10, 4),
            Vec2d(7, 1),
            Vec2d(4, 4),
            Vec2d(4, 17),
            Vec2d(4, 13),
            Vec2d(1, 16),
            Vec2d(2, 17),
    };

    //rotate and
    //move model a bit
    for (int i = 0; i < 11; i++) {
        pos[i] += Vec2d(-7,-10);
        pos[i] = transform * pos[i];
        pos[i] = pos[i] + cord;
    }

    Color color(0, 0, 0, 255);
    drawer->polygon(pos, 11, color);

}

void Bullet::onCollision(std::vector<Object *> &objects, std::vector<Object *>::iterator it) {
    objects.erase(it);
    delete this;
}
