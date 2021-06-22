#ifndef ANIMAL_H
#define ANIMAL_H

#include <string.h>
#include <iostream>

using std::string;

// Define differents struct to organize data concerning the Animals
struct Malade
{
    bool Is_Malade = false;
    int Max_Days; // The Max_Days variable means if the malade period (=days) exceeds the value, the Animals die
    int days = 0;
};

struct Hungry
{
    bool Is_Hungry = false;
    int Max_Days; // The Max_Days variable means if the Hungry period (=days) exceeds the value, the Animals die
    int days = 0;
};

struct Reproduction
{
    bool Is_Newer; // The animal cannot reproduce the first days after the arrival, that bool check if is New or not.
    bool Can_Reproduce; // Bool will check if the animal can reproduce 
    bool Is_Reproduction = false;
    int Reproduction_Duration;
    int days = 0;
};

struct Age
{
    // All Value are in month
    int Life_Esperance = 0;
    int Current_Age;
    int Sexual_Maturity = 0;
};

struct State
{
    Malade s_Malade;
    Hungry s_Hungry;
    Reproduction s_Reproduction;
    Age s_Age;
};

class Animal
{
    protected:
        bool m_Gender;         // True for male, false for female
        string m_Type_Of_Food; // Graine or viande
        float m_Food_Quantity; // Quantity of consommation food in kg
        State m_State;         // The state of the animal (hungry, malade, reproduction, Age...)
        int vv;

    public:
        Animal();
        Animal(bool gender, int age);
        void UpdateState();
        ~Animal();
};


void Animal::UpdateState() {
    // Update the State after each turn (1 month)
    /*
    * Update the age
    * Update the Reproduction State
    * Update 
    * 
    * 
    * 
    * 
    * 
    * 
    * 
    */
}


void UpdateReproductionState() {
    
}

#endif
