//
// Created by vm on 23.13.3.
//

#include "Object.h"


Object::Object(): collisionBox(&this->coordinates, 5) {

}

void Object::rotateByDeg(double a) {
    //calculate new rotational matrix
    double matr[2][2] = {
            {std::cos(a), -std::sin(a)},
            {std::sin(a), std::cos(a)}
    };
    transform = transform * Matrix2d(matr);
}

Vec2d Object::getLocalAcceleration() {
    return acceleration;
}

void Object::setLocalAcceleration(Vec2d acc) {
    this->acceleration = acc;
}

Vec2d Object::getLocalSpeed() {
    return transform * speed;
}

void Object::setLocalSpeed(Vec2d spd) {
    this->speed = transform * spd;
}

Vec2d Object::getGlobalSpeed() {
    return speed;
}

Vec2d &Object::getCords() {
    return coordinates;
}

void Object::setCords(Vec2d cord) {
    this->coordinates = cord;

}

Matrix2d Object::getTransformationMatrix() {
    return transform;
}

void Object::setGlobalSpeed(Vec2d spd) {
    this->speed = spd;
}

Vec2d Object::getGlobalAcceleration() {
    return this->transform * this->acceleration;
}

CollisionBox & Object::getCollisionBox() {
    return this->collisionBox;
}

void Object::tick() {
    time++;
    onTick();
}

bool Object::isMarkedForRemoval() {
    return markedForRemoval;
}

