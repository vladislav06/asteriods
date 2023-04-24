//
// Created by vm on 23.24.4.
//

#ifndef ASTEROIDS_SHOCKWAVE_H
#define ASTEROIDS_SHOCKWAVE_H


#include "../Object.h"

class Shockwave : public Object{
public:
    explicit Shockwave(Vec2d coordinates);

    void draw(Drawer *drawer) override;

    bool onCollision(Object &object, Vec2d direction) override;

private:
    void onTick() override;
};


#endif //ASTEROIDS_SHOCKWAVE_H
