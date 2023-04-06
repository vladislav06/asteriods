//
// Created by vm on 23.6.3.
//

#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else

#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif

#include "drawer/Drawer.h"
#include "object/Ship.h"
#include "physics/Physics.h"
#include "object/Asteroid.h"
#include "drawer/DrawLoop.h"
#include "physics/util.h"
#include "object/Dummy.h"

#define WIDTH 800
#define HEIGHT 600

std::vector<Object *> objects;

Drawer drawer;
DrawLoop drawLoop(drawer,objects);
Physics physics(HEIGHT, WIDTH,objects);
Ship ship;

void loop() {
    SDL_Event event;
    bool running = true;


    Color color{};

    while (running) {
        while (SDL_PollEvent(&event)) {
            //quit
            if (event.type == SDL_QUIT) {
                running = false;
                break;
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

            Bullet *bullet = ship.shoot();
            objects.push_back(bullet);
        }


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
    objects.push_back(&ship);

    for (int i = 0; i < 30; i++) {
        Asteroid *asteroid = new Asteroid((float) ((float) std::rand() / (float) RAND_MAX) * 2);
        asteroid->setCords(getRandomVector(500));
        asteroid->setLocalSpeed(getRandomVector(10));

        objects.push_back(asteroid);
    }


    loop();

    /* Frees memory */
    SDL_DestroyWindow(window);
    /* Shuts down all SDL subsystems */
    SDL_Quit();

    return 0;
}
