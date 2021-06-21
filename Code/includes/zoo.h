// #ifndef ZOO_H
// #define ZOO_H
#include <iostream>
#include "budget.h"
#include <string>
using namespace std;

class Zoo
{
private:
    // int Number_Of_Game;
    float m_Capital = 80000;
    /* data */
public:
    Zoo(/* args */);
    ~Zoo();
    void Menu();
};

Zoo::Zoo(/* args */)
{
}

Zoo::~Zoo()
{
}

void Zoo::Menu()
{
    string choice;
    cout << "Bienvenue dans ZooLand ! Ce simulateur de Zoo revisité vous propose son jeu en intégralité !" << endl;
    do
    {
    cout << "Que voulez vous faire ? Tapez 1 pour quitter, 2 pour lancer une partie : ";
    cin >> choice;
    } while (choice != "1" && choice != "2");

    if (choice == "1")
    {
        // leave the game
    } else
    {
        // start the game with the "cycle" function
    }
    
}