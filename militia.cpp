#include "militia.hpp"

Militia::Militia(SDL_Setup* passed_SDL_Setup, SDL_Texture* passed_image, int starting_x, int starting_y, int *passed_MouseX, int *passed_MouseY, Environment* passed_environment) :
Character( passed_SDL_Setup, passed_image, starting_x, starting_y, passed_MouseX, passed_MouseY, passed_environment)
{
    team = 1;
    health = 75;
    max_health = 75;
    attack = 0.015;
    defense = 0.001;
}

Militia::~Militia()
{
}

void Militia::Update(){

    Character::Update();

}
