//
// Created by vm on 23.6.3.
//

#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else

#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include <list>

#endif

#include "typeinfo"
#include "drawer/Drawer.h"
#include "object/Ship.h"
#include "physics/Physics.h"
#include "object/Asteroid.h"
#include "drawer/DrawLoop.h"
#include "physics/util.h"
#include "object/Dummy.h"
#include "world/World.h"
#include "object/Text.h"

#define WIDTH 800
#define HEIGHT 600

World *world = World::getInstance();
Drawer drawer;
Text text;
DrawLoop drawLoop(drawer, HEIGHT, WIDTH);
Physics physics(HEIGHT, WIDTH);
Ship ship;

void loop() {
    SDL_Event event;
    bool running = true;


    Color color{};

    auto objects = World::getInstance()->getObjects();
    objects->push_back(&text);


    while (running) {
        //tick every object
        for (auto it = objects->begin(); it != objects->end(); ++it) {
            (*it)->tick();
            if ((*it)->isMarkedForRemoval()) {
                delete *it;
                it = objects->erase(it);
            }
        }


        while (SDL_PollEvent(&event)) {
            //quit
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
            //handle projectile change
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_q && event.key.repeat == 0) {
                    ship.selectPreviousProjectileType();

                }
                if (event.key.keysym.sym == SDLK_e && event.key.repeat == 0) {
                    ship.selectNextProjectileType();

                }
            }
        }
        SDL_PumpEvents();
        const Uint8 *key = SDL_GetKeyboardState(nullptr);

        if (key[SDL_SCANCODE_W]) {
            ship.setLocalAcceleration(Vec2d(-1, 0));
        } else {
            ship.setLocalAcceleration(Vec2d(0, 0));
        }
        if (key[SDL_SCANCODE_A]) {
            ship.rotateByDeg(0.1);
        }
        if (key[SDL_SCANCODE_D]) {
            ship.rotateByDeg(-0.1);
        }
        if (key[SDL_SCANCODE_SPACE]) {
            Projectile *bullet = ship.shoot();
            if (bullet != nullptr)
                objects->push_back(bullet);
        }


        //debug//
        std::string debug = "" + std::to_string(ship.getCurrentProjectileType());

        for (Object *obj: *objects) {
            debug += typeid(*obj).name();
            debug += '\n';
        }
        text.text = debug;
        //debug//

        physics.loop();
        drawLoop.loop();
        SDL_Delay(16);
    }
}

int main() {
    srand(time(0));

    SDL_Window *window = SDL_CreateWindow("Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WIDTH,
                                          HEIGHT,
                                          SDL_WINDOW_RESIZABLE);
    drawer.init(window);

    //create objects
    ship.setCords(Vec2d(HEIGHT / 2, WIDTH / 2));
    World::getInstance()->getObjects()->push_back(&ship);
//
    for (int i = 0; i < 20; i++) {
        Asteroid *asteroid = new Asteroid((float) ((float) std::rand() / (float) RAND_MAX) * 2);
        asteroid->setCords(getRandomVector(500));
        asteroid->setLocalSpeed(getRandomVector(10));

        World::getInstance()->getObjects()->push_back(asteroid);
    }

//    Asteroid *asteroid = new Asteroid(1);
//    asteroid->setCords(Vec2d(200, 300));
//    World::getInstance()->getObjects()->push_back(asteroid);

    //


    loop();

    /* Frees memory */
    SDL_DestroyWindow(window);
    /* Shuts down all SDL subsystems */
    SDL_Quit();

    return 0;
}
