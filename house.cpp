#include "house.hpp"

House::House(SDL_Setup* sdl_setup, std::string FilePath, int x, int y) : Building(sdl_setup, FilePath, x, y)
{
    team = 1;
    health = 150;
    max_health = 150;
    attack = 0.00;
}

House::~House()
{
}

void House::Update()
{
    Building::Update();
}
