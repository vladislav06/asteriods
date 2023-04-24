//
// Created by vm on 23.6.3.
//

#include <memory>
#include "Ship.h"
#include "math.h"
#include "projectiles/Bullet.h"


// stuff for changing projectile type
typedef Projectile *(*Creator)(Vec2d pos, Matrix2d dir, Vec2d speed);

template<typename T>
Projectile *getProjectile(Vec2d pos, Matrix2d dir, Vec2d speed) {
    return new T(pos, dir, speed);
}

Creator projectileTypes[3];

Ship::Ship() {
    double matr[2][2] = {
            {0, 1},
            {1, 0}
    };
    this->transform.setMatrix(matr);

    projectileTypes[ROCKET] = getProjectile<Rocket>;
    projectileTypes[BULLET] = getProjectile<Bullet>;


}

void Ship::draw(Drawer *drawer) {

    Vec2d sideStart(-5, 0);
    Vec2d Lside(10, -5);
    Vec2d Rside(10, 5);
    Vec2d end1(8, -2.5);
    Vec2d end2(8, 2.5);

    sideStart = transform * sideStart;
    Lside = transform * Lside;
    Rside = transform * Rside;
    end1 = transform * end1;
    end2 = transform * end2;


    // do rotational matrix transform


    //do coordinate shift
    sideStart += this->coordinates;
    Lside += this->coordinates;
    Rside += this->coordinates;
    end1 += this->coordinates;
    end2 += this->coordinates;

    //draw
    Color color{};

    drawer->line(sideStart, Lside, color);
    drawer->line(sideStart, Rside, color);
    drawer->line(end1, end2, color);

}

bool Ship::onCollision(Object &object, Vec2d direction) {
    this->coordinates.x = 250;
    this->coordinates.y = 250;
    this->speed.x = 0;
    this->speed.y = 0;
    return false;
}


Projectile *Ship::shoot() {

    if (cooldownTime == 0) {

        Projectile *projectile = projectileTypes[projectileType](getCords() + (transform * Vec2d(-25, 0)),
                                                                 getTransformationMatrix(),
                                                                 getGlobalSpeed() + transform * Vec2d(-20, 0));
        cooldownTime = projectile->gunCoolDown();

        return projectile;
    } else {
        return nullptr;
    }
}

void Ship::onTick() {
    if (cooldownTime > 0) {
        cooldownTime--;
    }
}

void Ship::setProjectileType(Ship::ProjectileType projType) {
    this->projectileType = projType;
}

