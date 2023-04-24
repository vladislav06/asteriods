//
// Created by vm on 23.7.3.
//

#include <set>
#include "Physics.h"
#include "../world/World.h"
#include <typeinfo>

void Physics::loop() {
    std::vector<std::list<Object *>::iterator> objectsToDelete;

    auto objects = World::getInstance()->getObjects();

    for (auto it = objects->begin(); it != objects->end(); ++it) {
        Object *object = *it;
        if (object == nullptr)
            continue;
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
        for (auto it2 = objects->begin(); it2 != objects->end(); ++it2) {
            Object *obj2 = *it2;
            if (object == obj2)
                continue;

            std::string str = typeid(object).name();
            if (str == "9Shockwave") {
                printf("as");
            }
            bool b1 = object->getCollisionBox().collideWith(obj2->getCollisionBox());
            bool b2 = obj2->getCollisionBox().collideWith(object->getCollisionBox());
            if (b1 &&
                b2) {


                bool deleteObj2 = obj2->onCollision(*object, (obj2->getCords() - object->getCords()).normalise());
                bool deleteObj = object->onCollision(*obj2, (obj2->getCords() - object->getCords()).normalise());

                if (deleteObj2) {
                    it2 = objects->erase(it2);
                    delete obj2;
                }
                if (deleteObj) {
                    it = objects->erase(it);
                    delete object;
                    break;

                }
            }
        }
    }

    for (int i = 0; i < objectsToDelete.size(); ++i) {

        auto it = objectsToDelete[i];

        Object *obj = *it;

        objects->erase(it);
        delete obj;
    }
}
