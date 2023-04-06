//
// Created by vm on 23.13.3.
//

#include "Object.h"


Object::Object() : collisionBox(&this->cord, 5) {

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
    return acc;
}

void Object::setLocalAcceleration(Vec2d acc) {
    this->acc = acc;
}

Vec2d Object::getLocalSpeed() {
    return transform * speed;
}

void Object::setLocalSpeed(Vec2d speed) {
    this->speed = transform * speed;
}

Vec2d Object::getGlobalSpeed() {
    return speed;
}

Vec2d &Object::getCords() {
    return cord;
}

void Object::setCords(Vec2d cord) {
    this->cord = cord;

}

Matrix2d Object::getTransformationMatrix() {
    return transform;
}

void Object::setGlobalSpeed(Vec2d speed) {
    this->speed = speed;
}

Vec2d Object::getGlobalAcceleration() {
    return this->transform * this->acc;
}

CollisionBox & Object::getCollisionBox() {
    return this->collisionBox;
}

