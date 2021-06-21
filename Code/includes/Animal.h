#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal {
    protected:
        bool m_Gender; // True for male, false for female
        bool m_Malade; 
        int m_Age;
        string m_Type_Of_Food; // Graine of viande
        float m_Quatity; // Quantity of consommation food
    public:
        Animal(/* args */);
        ~Animal();
};

Animal::Animal(/* args */){

}

Animal::~Animal(){
    
}



#endif