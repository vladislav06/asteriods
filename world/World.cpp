//
// Created by vm on 23.17.4.
//

#include "World.h"

World *World::singleton_ = nullptr;


World *World::getInstance() {
    if (singleton_ == nullptr) {
        singleton_ = new World();
    }
    return singleton_;
}

World::World() {
}

std::list<Object *> *World::getObjects() {
    return &objects;
}
