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
    this->rotation.setMatrix(matr);
}

void Ship::rotateByDeg(double a) {
    //calculate new rotational matrix
    double matr[2][2] = {
            {std::cos(a), -std::sin(a)},
            {std::sin(a), std::cos(a)}
    };
    rotation = rotation * Matrix2d(matr);
}

Vec2d Ship::getLocalAcceleration() {
    return acc;
}

Vec2d Ship::getGlobalSpeed() {

    //do transformation using local speed and rotational matrix
    return speed;
}

Vec2d Ship::getLocalSpeed() {
    return speed;
}

Vec2d Ship::getCords() {
    return cord;
}

void Ship::setCords(Vec2d cord) {
    this->cord = cord;
}

void Ship::setLocalSpeed(Vec2d speed) {
    this->speed = speed;

}

void Ship::setLocalAcceleration(Vec2d acc) {
    this->acc = acc;
}

void Ship::draw(Drawer *drawer) {

    Vec2d sideStart(-5, 0);
    Vec2d Lside(10, -5);
    Vec2d Rside(10, 5);
    Vec2d end1(8, -2.5);
    Vec2d end2(8, 2.5);

    sideStart = rotation * sideStart;
    Lside = rotation * Lside;
    Rside = rotation * Rside;
    end1 = rotation * end1;
    end2 = rotation * end2;


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



