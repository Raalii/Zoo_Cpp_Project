#ifndef TIGRE_H
#define TIGRE_H

#include "zoo.hpp"

#include <string>

using namespace std;

class Tigre {

public:
    Tigre();
    Tigre(string name);
    virtual void fire();
};

#endif // TIGRE_H
