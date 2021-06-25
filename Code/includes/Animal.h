#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
#include <ctime>
#include <random>

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
    int Days_Without_Food = 0;
    bool Is_Hungry = false;
    int Max_Days; // The Max_Days variable means if the Hungry period (=days) exceeds the value, the Animals die
};

struct Reproduction
{
    bool Is_Newer; // The animal cannot reproduce the first days after the arrival, that bool check if is New or not.
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
    int Limite_Reproduction;
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

public:
    Animal();
    ~Animal();
    Animal(bool gender, int age);
    bool Get_Gender();
    void UpdateState();
    void Update_Hungry();
    void Update_Malade(bool Is_Surpopulation);
    bool Update_Reproduction();
    void Reset_Reproduction();
    void CheckMaladie(int Probability);
    void Eats_Food();
    void Reset_Hungry();
    bool Can_Reproduce(bool Surpopulation);
    bool Get_Is_Reproduction();
    string Get_Type_Of_Food();
    float Get_Food_Quantity();
    void Update_Age();
};




#endif
