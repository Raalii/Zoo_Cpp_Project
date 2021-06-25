#include "./includes/aigle.h"
#include <iostream>

// using namespace std;

Aigle::Aigle(/* args */)
{
}

Aigle::Aigle(bool gender, int age, int ID) : Animal(gender, age)
{
    // Informations about Maladie
    m_State.s_Malade.Max_Days = 30;
    // Hungry state
    m_State.s_Hungry.Max_Days = 10;
    // Reproduction state
    m_State.s_Age.Life_Esperance = 300; // = 25 years
    m_State.s_Age.Sexual_Maturity = 48; // = 4 years
    m_ID = ID;

    if (gender)
    {
        //  define all parametters for male Eagle
        m_Type_Of_Food = "viande";
        m_Food_Quantity = 0.25;
    }
    else
    {
        // define all parametters for female Eagle
        m_Type_Of_Food = "viande";
        m_Food_Quantity = 0.30;
    }
}

void Aigle::Print()
{
    std::cout << "************" << std::endl;
    std::cout << "\nID : " << m_ID << std::endl;
    std::cout << "\nAigle de " << m_State.s_Age.Current_Age << " mois, ";
    if (m_Gender)
    {
        std::cout << "male" << std::endl;
    }
    else
    {
        std::cout << "femelle" << std::endl;
    }

    std::cout << "Etat actuel : ";
    if (m_State.s_Malade.Is_Malade)
    {
        std::cout << "Malade";
    }
    else
    {
        std::cout << " en bonne sante !";
    }

    if (m_State.s_Reproduction.Is_Reproduction)
    {
        std::cout << " et en reproduction ! ";
    }

    std::cout << "\n***********" << std::endl;
}

Aigle::~Aigle()
{
}

float Aigle::CheckPriceValue()
// Function which will return the price of the current animal according to the age
{
    if (m_State.s_Malade.Is_Malade || m_State.s_Hungry.Is_Hungry)
    {
        return 0.0;
    }
    else
    {
        if (m_State.s_Age.Current_Age >= 6 && m_State.s_Age.Current_Age < 48)
        {
            return 500.0;
        }
        else if (m_State.s_Age.Current_Age >= 48 && m_State.s_Age.Current_Age < 168) // bewteen 4 years and 14
        {
            return 2000.0;
        }
        else
        {
            return 400.0;
        }
    }
}

int Aigle::Get_ID()
{
    return m_ID;
}