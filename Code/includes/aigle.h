#ifndef AIGLE_H
#define AIGLE_H

// #include "zoo.h"
#include "Animal.h"
// #include <iostream>
// #include "habitat.h"

class Habitat;

class Aigle : public Animal
{
private:
    int m_ID;
    /* Nous aurions pu utiliser un pointeur vers la classe, mais nous avons envoyé un mail pour ce problème, 
    sans réponse de votre part, puisqu'il y avait des erreurs d'include. Nous avons donc également utiisé un ID pour connaitre les habitats */
    int m_ID_Eagle_Habitat; // Link the animal and habitat to know in what habitat he are (useful when we have a lot of habitat)

public:
    Aigle(/* args */);
    Aigle(bool gender, int age, int ID);
    ~Aigle();
    float CheckPriceValue();
    int Get_ID();
    int Get_Habitat_ID();
    int Set_Habitat_ID();
    void Print();
};

#endif