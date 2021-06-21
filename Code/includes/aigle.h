#ifndef AIGLE_H
#define AIGLE_H

#include "zoo.h"
#include "Animal.h"
#include <iostream>

class Aigle :  public Animal
{
private:
    /* data */
public:
    Aigle(/* args */);
    Aigle(bool gender, int age);
    ~Aigle();
    float CheckPriceValue();
};



#endif