#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP
#include "imports.hpp"
#include <vector>
#include <list>
#include "sprite.hpp"
#include "sdl_setup.hpp"
#include "gold.hpp"
#include "building.hpp"
#include "submenu.hpp"
#include "collision_rectangle.hpp"
#include "ai.hpp"
#include <math.h>
#include "text.hpp"

class Character; //avoids error because Environment includes Character and vice versa
class Building;
class AI;

class Environment
{
    public:
        Environment(SDL_Setup* passed_sdl_setup, int *passed_MouseX, int *passed_MouseY, SubMenu* passed_menu, AI* passed_ai);
        ~Environment();

        void DrawBack();

        void Update();

        int getMenuType();
        void updateWhatToMake(int what);
        void updateCost(int n);
        bool shouldMenu();

        int team;

        std::vector<Building*> getBuildings() { return buildings; }
        std::vector<Gold*> getGoldMines() { return goldMines; }
        std::list<Character*> getCharacters() { return characters; }

        void AddResources(int i);

        void PrintResources() { std::cout << resources << std::endl; } //prints to command line, for testing only

        Character* Combat(Sprite* attacker, int attacker_team);
        Building* CombatBuilding(Sprite* attacker, int attacker_team);
        void KillCharacter(Sprite* passed_dead);

        Character* FindTarget(int x, int y);

        AI* ai;

        float resources;
        float orcResources;
        Character* selectedCharacter;
        Building* selectedBuilding;
        Gold* selectedGold;

        bool buildingConstructionCollision(int x, int y);

        void decreasePop(int team);

        int humanPop;
        int orcPop;
        int humanMaxPop;
        int orcMaxPop;

        int getOrcPop() { return orcPop; }
        int getOrcMaxPop() { return orcMaxPop; }

        void createVillager(Building* passed_building, int unit);
        void createMilitia(Building* passed_building, int unit);
        void createChampion(Building* passed_building, int unit);
    
        

    private:

        SubMenu* optionsMenu;

        CollisionRectangle collision_rect;

        int *MouseX;
        int *MouseY;

        int menuType;
        int whatToMake;
        bool showMenu;
    
        TextMessage* txt;

        Character* dead;

        SDL_Setup* sdl_setup;
        std::vector<Gold*> goldMines;
        std::vector<Building*> buildings;
        std::list<Character*> characters;

};

#endif // ENVIRONMENT_HPP
