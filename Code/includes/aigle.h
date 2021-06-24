#ifndef AIGLE_H
#define AIGLE_H

// #include "zoo.h"
#include "Animal.h"
// #include <iostream>
// #include "habitat.h"

class Habitat;

class Aigle :  public Animal
{
private:
    int m_ID;
    // Habitat m_Animal_Habitat;
public:
    Aigle(/* args */);
    Aigle(bool gender, int age);
    ~Aigle();
    float CheckPriceValue();
    int Get_ID();
    void tqt() {
        //  m_Animal_Habitat.display();
    };
    // void CheckReproduction();
};



#endif