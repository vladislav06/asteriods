//
// Created by vm on 23.7.3.
//

#include "Physics.h"

void Physics::loop() {
    for (auto it = objects.begin(); it != objects.end(); ++it) {
        Object *object = *it;
        //acceleration
        object->setGlobalSpeed(object->getGlobalSpeed() + object->getGlobalAcceleration());

        //move
        object->setCords(object->getCords() + (object->getGlobalSpeed() * (1. / 16.)));

        //check for out of screen

        if (object->getCords().x < 0)
            object->getCords().x = width;

        if (object->getCords().x > width)
            object->getCords().x = 0;

        if (object->getCords().y < 0)
            object->getCords().y = height;

        if (object->getCords().y > height)
            object->getCords().y = 0;
        //check for collision//call on collision

        for (auto it2 = objects.begin(); it2 != objects.end(); ++it2) {
            Object *obj2 = *it2;
            //   printf("1:%p | 2:%p\n", *it, *it2);
            if (object == obj2)
                continue;

            if((long)&(obj2->getCollisionBox()) == 0x10000){
                printf("asdasdasd");
            }

            try {
                if (object->getCollisionBox().collideWith(obj2->getCollisionBox())) {
                    object->onCollision(objects, it);
                }
            } catch (std::exception &e) {
                printf("%s", e.what());
            }

        }

    }
}
