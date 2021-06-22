#ifndef HABITAT_H
#define HABITAT_H

#include <iostream>
#include "zoo.h"
#include "budget.h"

struct habitat_animals
{
    int h_tigre;
    int h_aigle;
    int h_poule;
};

class habitat
{
protected:
    habitat_animals m_Habitat;
    int nbr_of_habitats;

public:
    habitat();
    ~habitat();
    float buy_habitat_for_animals(Budget Current_Budget);
    float sell_habitat_animals(Budget Current_Budget);
};


float habitat::buy_habitat_for_animals(Budget Current_Budget)
{
    int choice;
    do
    {
        std::cout << "Vous avez le choix entre plusieurs habitat" << std::endl;
        std::cin >> choice;
    } while (choice != 1 && choice != 2 && choice != 3);

    switch (choice)
    {
    case 1: /*Habitat tigre*/
        // alors le nombre habitat tigre +1
        m_Habitat.h_tigre += 1;
        Current_Budget.Buy_Habitat(2000);
        nbr_of_habitats +=1;
        break;

    case 2: /*Habitat aigle*/
        // alors le nombre habitat aigle +1
        m_Habitat.h_aigle += 1;
        Current_Budget.Buy_Habitat(2000);
        nbr_of_habitats +=1;
        break;
    case 3: /*Habitat poule*/
        // alors le nombre habitat poule +1
        m_Habitat.h_poule += 1;
        Current_Budget.Buy_Habitat(300);
        nbr_of_habitats +=1;
        break;
    default:
        break;
    }
}

float habitat::sell_habitat_animals(Budget Current_Budget) {
    int choice;

    do
    {
        std::cout << "Souhaitez-vous vendre un habitat ? " << std::endl;
        std::cout << "Si oui, lequels ? 1 habitat tigre, 2 habitat aigle, 3 habitat poules." << std::endl;
        std::cin >> choice;
    } while (choice != 1 && choice != 2 && choice != 3);

    switch (choice)
    {
    case 1: /*Habitat tigre*/
        // alors le nombre habitat tigre -1
        m_Habitat.h_tigre -= 1;
        Current_Budget.Sell_Habitat(500);
        nbr_of_habitats +=1;
        break;

    case 2: /*Habitat aigle*/
        // alors le nombre habitat aigle +1
        m_Habitat.h_aigle += 1;
        Current_Budget.Sell_Habitat(500);
        nbr_of_habitats +=1;
        break;
    case 3: /*Habitat poule*/
        // alors le nombre habitat poule +1
        m_Habitat.h_poule += 1;
        Current_Budget.Sell_Habitat(3);
        nbr_of_habitats +=1;
        break;
    default:
        break;
    }
}



/*
==> Action 1 ?
   * Voulez vous acheter ? 
        * Quels animal voulez vous vendre ?  [] 
* 
*
==> Action 2 ?
    * Voulez vous acheter ?
        * ==> 
    * Voulez vous vendre ?
        * ==> 
==> Action 3 ?   
*
*
*
*
*
*
*/

// habitat::habitat(/* args */)
// {
// }

// habitat::~habitat()
// {
// }

#endif