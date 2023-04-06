//
// Created by vm on 23.15.3.
//

#include "CollisionBox.h"
#include "math.h"

bool CollisionBox::collideWith(CollisionBox &anotherBox) {
    //check for collision by subtracting coordinates and checking if difference is less than radius
    return std::abs(this->coordinates->x - anotherBox.coordinates->x) <= this->radius + anotherBox.radius &&
           std::abs(this->coordinates->y - anotherBox.coordinates->y) <= this->radius + anotherBox.radius;
}