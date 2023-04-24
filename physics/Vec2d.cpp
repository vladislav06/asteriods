//
// Created by vm on 23.7.3.
//

#include "Vec2d.h"
#include <cmath>

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
    return {this->x * a, this->y * a};
}

Vec2d Vec2d::operator-(Vec2d other) const {
    return {this->x - other.x, this->y - other.y};
}

void Vec2d::operator-=(Vec2d other) {
    this->x -= other.x;
    this->y -= other.y;
}

Vec2d Vec2d::operator-() const {
    return {-this->x, -this->y};
}

Vec2d Vec2d::normalise() {
    return {
            this->x /= length(),
            this->y /= length(),
    };

}

double Vec2d::length() {
    return std::sqrt(x * x + y * y);
}


