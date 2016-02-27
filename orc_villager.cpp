#include "orc_villager.hpp"

OrcVillager::OrcVillager(SDL_Setup* passed_SDL_Setup, std::string FilePath, int starting_x, int starting_y, int *passed_MouseX, int *passed_MouseY, Environment* passed_environment) :
    Character( passed_SDL_Setup, FilePath, starting_x, starting_y, passed_MouseX, passed_MouseY, passed_environment)
{
    team = 2;
    health = 50;
    max_health = 50;
    attack = 0.01;
    defense = 0;

}

OrcVillager::~OrcVillager()
{
}

void OrcVillager::Update(){

    Character::Update();
    //Mining for VILLAGER class
    for (int i = 0; i < environment->getGoldMines().size(); i++) //check for collision with gold mines (mining)
    {
        if (unit->isColliding(environment->getGoldMines()[i]->GetGold()->GetCollisionRect()))
        {
            if (environment->getGoldMines()[i]->Mining()) //if resources successfully mined (ie gold mine isn't empty)
            {
                environment->AddResources(2);
                //environment->PrintResources(); //for testing only
            }
        }
    }
}
