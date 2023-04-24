//
// Created by vm on 23.18.4.
//

#ifndef ASTEROIDS_SMOKE_H
#define ASTEROIDS_SMOKE_H


#include "../Object.h"

class Smoke : public Object{
public:
    explicit Smoke(Vec2d coordinates);

    void draw(Drawer *drawer) override;

    bool onCollision(Object &object, Vec2d direction) override;

private:
    void onTick() override;
};


#endif //ASTEROIDS_SMOKE_H
