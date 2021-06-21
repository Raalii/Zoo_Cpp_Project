#include "./includes/zoo.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

Zoo::Zoo(/* args */)
{
    
}

Zoo::~Zoo()
{
}

void Zoo::Menu()
{
    string choice;
    cout << "Bienvenue dans ZooLand ! Ce simulateur de Zoo revisite vous propose son jeu en integralite !" << endl;
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