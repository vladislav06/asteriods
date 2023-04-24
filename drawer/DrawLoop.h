//
// Created by vm on 23.20.3.
//

#ifndef ASTEROIDS_DRAWLOOP_H
#define ASTEROIDS_DRAWLOOP_H


#include <vector>
#include <list>
#include "../object/Object.h"
#include "../world/World.h"

class DrawLoop {
private:
    Drawer &drawer;
public:
    DrawLoop(Drawer &drawer) :
            drawer(drawer) {};

    void loop();

};


#endif //ASTEROIDS_DRAWLOOP_H
