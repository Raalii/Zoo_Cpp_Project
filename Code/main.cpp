/*
* Simulateur de Zoo

* Ce projet consiste à créer un simulateur permettant la gestion d'un zoo en tour par tour. Chaque tour représente 1 mois.

Notre simulateur doit mettre en place : 
    - Un scénario avec : 2 couples de tigre, 2 couples d'aigle, 1 coq, 10 poules sur "10 ANS".
    - Des Classes (Animaux, tigre, poules, zoo etc..)
    - La gestion des 4 actions :
        - Achat/Vente animal ;
        - Achat nourriture ;
        - Achat/Vente Habitat;
        - Tour suivant;
    - La gestion des 10 événements :
        - Grossesses ;
        - Naissance ;
        - Mort Infantile ;
        - Fin de vie ;
        - Surpopulation ;
        - Maladie;
        Execptionnels par mois :
            - Incendie ;
            - Vol ;
            - Nuisibles ; 
            - Viande avariée
*/

#include "./includes/zoo.h"
#include "./includes/Animal.h"
#include "./includes/budget.h"
#include "./includes/aigle.h"
#include "./includes/poule.h"
#include "./includes/tigre.h"
#include <string>
#include <iostream>
#include <vector>



int main() {
    Zoo NewGame;
    NewGame.Menu();
    Aigle v(false, 144);
    std::cout << v.CheckPriceValue() << std::endl << v.Can_Reproduce() << std::endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     v.Update_Malade(true);
    //     // std::cout << "hello" << std::endl;
    // }
    v.tqt();
    
    

    // cout << c << endl;
    return 0;
}