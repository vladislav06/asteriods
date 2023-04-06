//
// Created by vm on 23.27.3.
//

#ifndef ASTEROIDS_DUMMY_H
#define ASTEROIDS_DUMMY_H


#include "Object.h"

class Dummy : public Object{

public:
    Dummy(float aa, float ab, float ba, float bb);

    void draw(Drawer *drawer) override;

    void onCollision(std::vector<Object *> &objects, std::vector<Object *>::iterator it) override;

};


#endif //ASTEROIDS_DUMMY_H
