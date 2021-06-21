#ifndef AIGLE_H
#define AIGLE_H

#include "zoo.h"
#include "Animal.h"
#include <iostream>

using namespace std;

class Aigle:public Animal {
    public:
        // constructor
        Aigle();
        // destructor
        ~Aigle();
};


#endif