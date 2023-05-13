//
// Created by vm on 23.20.3.
//

#include "DrawLoop.h"

void DrawLoop::loop() {
    drawer.fill(255, 255, 255);
    for (Object *object: *World::getInstance()->getObjects()) {

        object->draw(&drawer);

    }

    //draw player hud
    //right bottom corner
    Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    drawer.rectangle(Vec2d(width - 50, height - 50), Vec2d(width, height), color);


    drawer.present();
}
