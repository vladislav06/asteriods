//
// Created by vm on 23.20.4.
//

#include "Text.h"

bool Text::onCollision(Object &object, Vec2d direction) {
    return false;
}

void Text::draw(Drawer *drawer) {
    drawer->setFontsize(9);
    drawer->text(text, coordinates);
}

void Text::onTick() {

}
