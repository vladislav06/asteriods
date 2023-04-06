//
// Created by vm on 23.7.3.
//

#include "Color.h"

uint32_t Color::toUint32() {
    return r << 24 |
           g << 16 |
           b << 8 |
           a << 1;
}
