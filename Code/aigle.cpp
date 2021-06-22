#include "./includes/aigle.h"
#include <iostream>

// using namespace std;

Aigle::Aigle(/* args */)
{
}

Aigle::Aigle(bool gender, int age) : Animal(gender, age)
{
    if (gender)
    {
        // * define all parametters for male Eagle
        m_Type_Of_Food = "viande";
        m_Food_Quantity = 0.25;
        // Hungry state
        m_State.s_Hungry.Max_Days = 10;
        // Informations about Age
        m_State.s_Age.Life_Esperance = 300; // = 25 years
        m_State.s_Age.Sexual_Maturity = 48; // = 4 years
        // Informations about Maladie
        m_State.s_Malade.Max_Days = 30;
        // * Reproduction state
        // Function which will Update, Or set the reproduction state of the animal
        /* Fin de reproduction 14 ans*/
    }
    else
    {
        /* define all parametters for female Eagle */
        m_Type_Of_Food ="viande";
        m_Food_Quantity = 0.30;
        // Hungry state
        m_State.s_Hungry.Max_Days = 10;
        // Informations about Age
        m_State.s_Age.Life_Esperance = 300; // = 25 years
        m_State.s_Age.Sexual_Maturity = 48; // = 4 years
        if (/*la femelle est en gestation*/true)
        {
            /* nourriture x2 */
            m_Food_Quantity = 0.60;
            /* 2 oeufs en Mars*/
            /* Gestation 45 jours + Mort Infantile 50% */
            /* Fin de reproduction 14 ans*/
        }        
    }
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