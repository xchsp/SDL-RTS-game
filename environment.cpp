#include "environment.hpp"

Environment::Environment(SDL_Setup* passed_sdl_setup, int *passed_MouseX, int *passed_MouseY)
{
    sdl_setup = passed_sdl_setup;
    MouseX = passed_MouseX;
    MouseY = passed_MouseY;

    showMenu = false;
    menuType = 1;

    resources = 100;

    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            grass[i][j] = new Sprite(sdl_setup->GetRenderer(), "images/grass.bmp", i*50, j*50, 50, 50, CollisionRectangle(0,0,0,0)); //map, currently tiled, will eventually be one big grass tile
        }
    }

    selectedCharacter = new Character(sdl_setup, "images/villager.png", 300, 150, MouseX, MouseY, this); //game begins with villager selected to avoid error of deselecting an unselected character below
    selectedCharacter->unSelect();

    characters.push_back(selectedCharacter);
    characters.push_back(new Character(sdl_setup, "images/villager.png", 350, 150, MouseX, MouseY, this)); // "this" is instance of current class
    buildings.push_back(new Building(sdl_setup, "images/house.png", 200, 200));
    goldMines.push_back(new Gold(sdl_setup, 50, 50));
    goldMines.push_back(new Gold(sdl_setup, 600, 200));
    goldMines.push_back(new Gold(sdl_setup, 550, 500));
    goldMines.push_back(new Gold(sdl_setup, 720, 100));



}

Environment::~Environment()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            delete grass[i][j];
        }
    }
    for (std::vector<Gold*>::iterator i = goldMines.begin(); i != goldMines.end(); ++i)
    {
        delete (*i);
    }
    for (std::vector<Building*>::iterator i = buildings.begin(); i != buildings.end(); ++i)
    {
        delete (*i);
    }
    goldMines.clear();
    buildings.clear();
}

void Environment::DrawBack()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            grass[i][j]->Draw();
        }
    }

    for (std::vector<Gold*>::iterator i = goldMines.begin(); i != goldMines.end(); ++i)
    {
        (*i)->DrawGold();
    }

    for (std::vector<Building*>::iterator i = buildings.begin(); i != buildings.end(); ++i)
    {
        (*i)->DrawBuilding();
    }

        for (std::list<Character*>::iterator i = characters.begin(); i != characters.end(); ++i)
    {
        (*i)->Draw();
    }
}

void Environment::AddResources()
{
    resources = resources + 0.005;
}

int Environment::getMenuType()
{
    return menuType;
}

bool Environment::shouldMenu()
{
    return showMenu;
}

void Environment::Update(int whatToMake)
{

    for (std::list<Character*>::iterator i = characters.begin(); i != characters.end(); ++i)
    {
        (*i)->Update();
    }

    if (sdl_setup->GetEv()->type == SDL_MOUSEBUTTONDOWN)
    {
        if (sdl_setup->GetEv()->button.button == SDL_BUTTON_LEFT)
        {
            
            for (std::vector<Building*>::iterator iter = buildings.begin(); iter != buildings.end(); ++iter){
                if(*MouseX >= ((*iter)->getStructureX()) && *MouseX <= ((*iter)->getStructureX()+(*iter)->getStructureW()) && *MouseY >= ((*iter)->getStructureY()) && *MouseY <= ((*iter)->getStructureY()+(*iter)->getStructureH())){
                        (*iter)->Select();
                    if(menuType == 2){
                        menuType = 1;
                    }else{
                        menuType = 2;
                    }
                }
            }

            for (std::list<Character*>::iterator i = characters.begin(); i != characters.end(); ++i)
            {
                if(*MouseX >= ((*i)->getCharacterX()-15) && *MouseX <= ((*i)->getCharacterX()+(*i)->getCharacterW()-15) && *MouseY >= ((*i)->getCharacterY()-20) && *MouseY <= ((*i)->getCharacterY()+(*i)->getCharacterH()-20))
                {
                    selectedCharacter->unSelect(); //unselect previously selected
                    (*i)->setSelected();
                    selectedCharacter = (*i); //reassign selected character for future deselection
                    break; //prevent selection of multiple characters in same area
                }
                selectedCharacter->unSelect(); //unselect previously selected
            }
            
            if(whatToMake== 1){
                buildings.push_back(new Building(sdl_setup, "images/house.png", *MouseX-50, *MouseY-50));
            }else if(whatToMake == 2){
                characters.push_back(new Character(sdl_setup, "images/villager.png",*MouseX-50, *MouseY-50, MouseX, MouseY, this));
            }
             //testing
            // //testing
        }
    }

    if(sdl_setup->GetEv()->type == SDL_KEYDOWN){
       // if(sdl_setup->GetEv()->button.button == SDLK_SPACE){
            if(showMenu){
                showMenu = false;
            }else{
                showMenu = true;
            }
        //}
    }
}


