//
// Created by vm on 23.20.3.
//

#include "DrawLoop.h"

void DrawLoop::loop() {
    drawer.fill(255, 255, 255);
    for (Object *object: *World::getInstance()->getObjects()) {

        object->draw(&drawer);

    }


    drawer.present();
}
