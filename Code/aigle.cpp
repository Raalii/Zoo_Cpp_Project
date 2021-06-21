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
       /* define all parametters for male Eagle */
   }
   else
   {
       /* define all parametters for female Eagle */
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