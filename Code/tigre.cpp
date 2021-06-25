#include "./includes/tigre.h"
#include <iostream>
Tigre::Tigre(/* args */)
{
}

Tigre::Tigre(bool gender, int age, int ID) : Animal(gender, age)
{
    // Informations about Maladie
    m_State.s_Malade.Max_Days = 15;
    // Hungry state
    m_State.s_Hungry.Max_Days = 2;
    // Reproduction state
    m_State.s_Age.Life_Esperance = 300; // = 25 years
    m_ID = ID;

    if (gender)
    {
        //  define all parametters for male Ea        
        m_Type_Of_Food = "viande";
        m_Food_Quantity = 12;
        m_State.s_Age.Sexual_Maturity = 72; // = 6 years
    }
    else
    {
        // define all parametters for female Ea
        m_Type_Of_Food = "viande";
        m_Food_Quantity = 10;
        m_State.s_Age.Sexual_Maturity = 48; // = 4 years
    }
}

void Tigre::Print()
{
    std::cout << "----------" << std::endl;
    std::cout << "ID : " << m_ID << std::endl;
    std::cout << "\nTigre de " << m_State.s_Age.Current_Age << " mois, ";
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
    std::cout << "\n----------" << std::endl;
}

Tigre::~Tigre()
{
}

float Tigre::CheckPriceValue()
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
            return 1500.0;
        }
        else if (m_State.s_Age.Current_Age >= 48 && m_State.s_Age.Current_Age < 168) // bewteen 4 years and 14
        {
            return 60000.0;
        }
        else
        {
            return 10000.0;
        }
    }
}

int Tigre::Get_ID()
{
    return m_ID;
}
