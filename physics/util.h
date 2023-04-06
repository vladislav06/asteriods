//
// Created by vm on 23.20.3.
//

#ifndef ASTEROIDS_UTIL_H
#define ASTEROIDS_UTIL_H

#include <stdlib.h>
#include <ctime>
#include "Vec2d.h"


Vec2d getRandomVector(float max) {
    return Vec2d((float) ((float) std::rand() / (float) RAND_MAX) * max - (max / 2),
                 (float) ((float) std::rand() / (float) RAND_MAX) * max - (max / 2));
}

#endif //ASTEROIDS_UTIL_H
