#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <stdlib.h> /* srand, rand */
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
    void UpdateState();
    void Update_Hungry();
    void Update_Malade();
    void CheckMaladie(int Probability);
    void Eats_Food();
    bool Can_Reproduce();
    string Get_Type_Of_Food();
    int Get_Food_Quantity();
};

bool Animal::Can_Reproduce()
{
    // If the Animal are Malade, Angry, or he's not in sexual period
    if (m_State.s_Hungry.Is_Hungry || m_State.s_Age.Current_Age < m_State.s_Age.Sexual_Maturity || m_State.s_Age.Current_Age >= m_State.s_Age.Limite_Reproduction || m_State.s_Malade.Is_Malade)
    {
        return false;
    }
    return true;
}

void Animal::Update_Malade()
{
    if (m_State.s_Malade.Is_Malade)
    {
        if (m_State.s_Malade.Max_Days <= m_State.s_Malade.days)
        {
            m_State.s_Malade.Is_Malade = false;
            m_State.s_Malade.days = 0;
        }
        else
        {
            m_State.s_Malade.days += 30;

            if (m_State.s_Malade.days >= m_State.s_Malade.Max_Days)
            {
                m_State.s_Malade.Is_Malade = false;
                m_State.s_Malade.days = 0;
                std::cout << "Votre animal n'est plus malade ! " << std::endl;
            }
        }
    }
    else
    {
        if (true/* SURPOPULATION */)
        {
            CheckMaladie(50); // 50% chance to be Malade with surpopulation
        }
        CheckMaladie(30); // 30% chance to be Malade
    }
}

void Animal::CheckMaladie(int Probability)
{
    if (rand() % 101 < Probability) // if the random value (0-100) returned are inferior than Probability (=Probability% of chance)
    {
        m_State.s_Malade.Is_Malade = true;
        std::cout << "Votre animal est malade " << std::endl;
    }
}

string Animal::Get_Type_Of_Food() {
    return m_Type_Of_Food;
}

int Animal::Get_Food_Quantity() {
    return m_Food_Quantity;
}   

void Animal::Update_Hungry()
{
}

void Animal::UpdateState()
{
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

void UpdateReproductionState()
{
}

#endif
