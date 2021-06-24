#ifndef TIGRE_H
#define TIGRE_H

#include "Animal.h"
#include <iostream>
#include <string>

class Tigre:public Animal {
    private:
        int m_ID;
        /* Nous aurions pu utiliser un pointeur vers la classe, mais nous avons envoyé un mail pour ce problème, 
        sans réponse de votre part, puisqu'il y avait des erreurs d'include. Nous avons donc également utiisé un ID pour connaitre les habitats */
        int m_ID_Hen_Habitat; // Link the animal and habitat to know in what habitat he are (useful when we have a lot of habitat)
    public:
        Tigre(/* args */);
        ~Tigre();   
        Tigre(bool gender, int age, int ID); 
        float CheckPriceValue();
        int Get_ID();
        int Get_Habitat_ID();
        int Set_Habitat_ID();
        void Print();
};


#endif // TIGRE_H