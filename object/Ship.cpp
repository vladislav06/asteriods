//
// Created by vm on 23.6.3.
//

#include "Ship.h"
#include "math.h"

Ship::Ship() {
    double matr[2][2] = {
            {0, 1},
            {1, 0}
    };
    this->transform.setMatrix(matr);
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
    sideStart += this->cord;
    Lside += this->cord;
    Rside += this->cord;
    end1 += this->cord;
    end2 += this->cord;

    //draw
    Color color{};

    drawer->line(sideStart, Lside, color);
    drawer->line(sideStart, Rside, color);
    drawer->line(end1, end2, color);

}

void Ship::onCollision(std::vector<Object *> &objects, std::vector<Object *>::iterator it) {
    this->cord.x = 250;
    this->cord.y = 250;
    this->speed.x = 0;
    this->speed.y = 0;
}

Bullet *Ship::shoot() {
    Bullet *bullet = new Bullet(getCords() + (transform * Vec2d(-15, 0)),
                                getTransformationMatrix(),
                                getGlobalSpeed() + transform * Vec2d(-20, 0));
    return bullet;
}

