//
// Created by vm on 23.20.3.
//

#ifndef ASTEROIDS_DRAWLOOP_H
#define ASTEROIDS_DRAWLOOP_H


#include <vector>
#include "../object/Object.h"

class DrawLoop {
private:
    Drawer &drawer;
public:
    DrawLoop(Drawer &drawer, std::vector<Object *> &objects) :
            drawer(drawer),
            objects(objects) {};

    std::vector<Object *> &objects;

    void loop();

};


#endif //ASTEROIDS_DRAWLOOP_H
