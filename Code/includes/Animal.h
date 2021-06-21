#include <string>
#include <iostream>

using namespace std;

class Animal
{
protected:
    bool m_Gender; // True for male, false for female
    bool m_Malade; 
    int m_Age;
    string m_Type_Of_Food; // Graine of viande
    float m_Food_Quantity; // Quantity of consommation food in kg
public:
    Animal(/* args */);
    ~Animal();
};

Animal::Animal(/* args */)
{
}

Animal::~Animal()
{
}