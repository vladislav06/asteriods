//
// Created by vm on 23.20.4.
//

#ifndef ASTEROIDS_TEXT_H
#define ASTEROIDS_TEXT_H


#include "Object.h"

class Text : public Object {
public:
    std::string text;

    bool onCollision(Object &object, Vec2d direction) override;

    void draw(Drawer *drawer) override;

protected:
    void onTick() override;
};


#endif //ASTEROIDS_TEXT_H
