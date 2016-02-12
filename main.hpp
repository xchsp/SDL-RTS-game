#ifndef MAIN_HPP_INCLUDED
#define MAIN_HPP_INCLUDED
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "sdl_setup.hpp"
#include "sprite.hpp"
#include "character.hpp"

class Main
{
public:
    Main();
    ~Main();

    void GameLoop();

    double GetDistance(int x1, int y1, int x2, int y2);

private:

    Character *unit;
    bool quit;

    Sprite* grass;

    SDL_Setup* sdl_setup;

    int timeCheck;
    int MouseX;
    int MouseY;
    bool follow;
    int follow_point_x;
    int follow_point_y;
    float angle;
    float distance;
    bool stopAnimation;

};


#endif // MAIN_HPP_INCLUDED
