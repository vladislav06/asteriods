//
// Created by vm on 23.7.3.
//

#include "Vec2d.h"

Vec2d::Vec2d(double x, double y) {
    this->x = x;
    this->y = y;
}

Vec2d Vec2d::operator+(Vec2d other) const {
    return {this->x + other.x, this->y + other.y};
}

void Vec2d::operator+=(Vec2d other) {
    this->x += other.x;
    this->y += other.y;
}

Vec2d Vec2d::operator*(double a) const {
    return Vec2d(this->x * a, this->y * a);
}


