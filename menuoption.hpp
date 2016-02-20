
#ifndef MENUOPTION_HPP_INCLUDED
#define MENUOPTION_HPP_INCLUDED
#include "imports.hpp"
#include "sprite.hpp"
#include "building.hpp"
#include <vector>

class MenuOption
{
public:
    MenuOption(int kind, int price, std::string picString);
    MenuOption();
    ~MenuOption();

    std::string getPic();
    int getType();
    
    bool selected;

private:

    int type;
    int cost;

    std::string pic;


};


#endif // CHARACTER_HPP_INCLUDED
