//

#include "Asteroid.h"
#include "../world/World.h"
#include <SDL2_gfxPrimitives.h>
#include <typeinfo>

//
// Created by vm on 23.13.3.
Asteroid::Asteroid(float size){

    this->size = size;
    double matr[2][2] = {
            {0,    size},
            {size, 0}
    };
    this->transform.setMatrix(matr);


    this->collisionBox = CollisionBox(&this->coordinates, 15 * size);
}

void Asteroid::draw(Drawer *drawer) {
    Vec2d pos[8] = {
            Vec2d(-10, -2),
            Vec2d(-22, -1),
            Vec2d(-8, 13),
            Vec2d(2, 5),
            Vec2d(17, 1),
            Vec2d(15, -11),
            Vec2d(-3, -14),
            Vec2d(-10, -2)
    };

    for (int i = 0; i < 8; i++) {
        pos[i] = transform * pos[i];
        pos[i] = pos[i] + coordinates;
    };

    Color color(0, 0, 0, 255);
    drawer->polygon(pos, 8, color);
}

bool Asteroid::onCollision(Object &object, Vec2d direction) {
    if (typeid(object) == typeid(*this)) {
        return false;
    }
    // if asteroid is too small to be divided into two
    if (size < 0.5) {
        return true;
    }

    // generate two smaller asteroids that moves in opposite directions
    // perpendicular to impact direction

    Matrix2d rotMatrix(90);

    Asteroid *asteroid1 = new Asteroid(this->size / 2);
    asteroid1->setCords(this->coordinates);
    asteroid1->setGlobalSpeed(rotMatrix * (direction * 5));

    Asteroid *asteroid2 = new Asteroid(this->size / 2);
    asteroid2->setCords(this->coordinates);
    asteroid2->setGlobalSpeed(rotMatrix * (-direction * 5));


    World::getInstance()->getObjects()->push_back(asteroid1);
    World::getInstance()->getObjects()->push_back(asteroid2);


    return true;
}

void Asteroid::onTick() {

}
