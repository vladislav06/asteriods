//
// Created by vm on 23.17.4.
//

#ifndef ASTEROIDS_WORLD_H
#define ASTEROIDS_WORLD_H

#include <list>
#include "../object/Object.h"
#include "../drawer/DrawLoop.h"
#include "../physics/Physics.h"

class World {
protected:
    World();

    static World *singleton_;
public:

    /// World cant be assignable
    World(World &other) = delete;

    /**
     * Singletons should not be assignable.
     */
    void operator=(const World &) = delete;

    /// Return instance of the world
    static World *getInstance();


    /// Normal code ============
private:

    /// List of all objects that exist in the world
    std::list<Object *> objects;

public:

    std::list<Object *> * getObjects();

};


#endif //ASTEROIDS_WORLD_H
