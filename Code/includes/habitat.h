#ifndef HABITAT_H
#define HABITAT_H

// #include <iostream>
// // #include "zoo.h"
// // #include "int.h"
#include "aigle.h"
#include "tigre.h"
#include "poule.h"
#include <string>
#include <vector>

// using namespace std;

class Habitat
{
protected:
    int m_Capacity = -1; // if the class are not defined, the default value are -1.

public:
    Habitat();
    Habitat(int Capacity);
    ~Habitat();
    void display() {
        std::cout << "Hello sa maman" << std::endl;
    }
};


class Eagle_Habitat : public Habitat
{
private:
    std::vector<Aigle> m_Current_Habitat = std::vector<Aigle>(5);
public:
    Eagle_Habitat(/* args */);
    ~Eagle_Habitat();
    void Delete_Animal(int ID);
    bool Add_Animal_In_Habitat(Aigle Current_Animal);
    std::vector<Aigle> Get_All_Animals();
    bool Is_Surpopulation();
};


class Tiger_Habitat : public Habitat
{
private:
    
public:
    Tiger_Habitat();
    ~Tiger_Habitat();
};



class Hen_Habitat : public Habitat
{
private:
    /* data */
public:
    Hen_Habitat(/* args */);
    ~Hen_Habitat();
};

// struct habitat_animals
// {
//     int h_tigre;
//     int h_aigle;
//     int h_poule;
// };

// class habitat
// {
// private:
//     habitat_animals m_Habitat;
//     int nbr_of_habitats;

//     /*
//     * Type ==> Tigre, Poule, Aigle
//     * Size ==> Différentes (Tigre : 2, Poule : 10, Aigle : 4)
//     * Enfant Tigre ==> Tableau de 4 place de Tigre.
//     *
//     */

// public:
//     habitat(/* args */);
//     ~habitat();
//     void buy_habitat_for_animals();
//     void sell_habitat_animals();
// };

// habitat::habitat(/* args */)
// {
// }

// habitat::~habitat()
// {
// }

// void habitat::buy_habitat_for_animals()
// {
//     int choice;
//     do
//     {
//         std::cout << "Vous avez le choix entre plusieurs habitat" << std::endl;
//         std::cin >> choice;
//     } while (choice != 1 && choice != 2 && choice != 3);

//     switch (choice)
//     {
//     case 1: /*Habitat tigre*/
//         // alors le nombre habitat tigre +1
//         m_Habitat.h_tigre += 1;
//         nbr_of_habitats += 1;
//         break;

//     case 2: /*Habitat aigle*/
//         // alors le nombre habitat aigle +1
//         m_Habitat.h_aigle += 1;
//         nbr_of_habitats += 1;
//         break;
//     case 3: /*Habitat poule*/
//         // alors le nombre habitat poule +1
//         m_Habitat.h_poule += 1;
//         nbr_of_habitats += 1;
//         break;
//     default:
//         break;
//     }
// }

// void habitat::sell_habitat_animals()
// {
//     int choice;

//     do
//     {
//         std::cout << "Souhaitez-vous vendre un habitat ? " << std::endl;
//         std::cout << "Si oui, lequels ? 1 habitat tigre, 2 habitat aigle, 3 habitat poules." << std::endl;
//         std::cin >> choice;
//     } while (choice != 1 && choice != 2 && choice != 3);

//     switch (choice)
//     {
//     case 1: /*Habitat tigre*/
//         // alors le nombre habitat tigre -1
//         m_Habitat.h_tigre -= 1;
//         // Current_Budget.Sell_Habitat(500);
//         nbr_of_habitats += 1;
//         break;

//     case 2: /*Habitat aigle*/
//         // alors le nombre habitat aigle +1
//         m_Habitat.h_aigle += 1;
//         // Current_Budget.Sell_Habitat(500);
//         nbr_of_habitats += 1;
//         break;
//     case 3: /*Habitat poule*/
//         // alors le nombre habitat poule +1
//         m_Habitat.h_poule += 1;
//         // Current_Budget.Sell_Habitat(3);
//         nbr_of_habitats += 1;
//         break;
//     default:
//         break;
//     }
// }

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