//
// Created by vm on 23.18.4.
//

#include "util.h"

Vec2d getRandomVector(float max) {
    return Vec2d((float) ((float) std::rand() / (float) RAND_MAX) * max - (max / 2),
                 (float) ((float) std::rand() / (float) RAND_MAX) * max - (max / 2));
}

int getRandomInt(int max) {
    return ((float) std::rand() / (float) RAND_MAX) * max;
}