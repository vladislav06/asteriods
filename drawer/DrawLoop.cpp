//
// Created by vm on 23.20.3.
//

#include "DrawLoop.h"

void DrawLoop::loop() {
    drawer.fill(255, 255, 255);
    for (Object *object: objects) {

        object->draw(&drawer);

    }
    drawer.text("lol", Vec2d(50, 50));
    drawer.present();

}
