#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include "budget.h"
#include <string>

class Zoo
{
private:
    Budget m_Budget;
    // int Number_Of_Game;
    /* data */
public:
    Zoo(/* args */);
    ~Zoo();
    void Menu();
};

#endif