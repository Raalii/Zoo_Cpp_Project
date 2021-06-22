#include "./includes/Animal.h"
#include "./includes/aigle.h"
#include "./includes/tigre.h"
#include "./includes/poule.h"


Animal::Animal(/* args */)
{
}


Animal::Animal(bool gender, int age) : m_Gender(gender)
{
    m_State.s_Age.Current_Age = age;
}

Animal::~Animal()
{
}

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
        if (m_State.s_Malade.Max_Days == m_State.s_Malade.days)
        {
            m_State.s_Malade.Is_Malade = false;
            m_State.s_Malade.days = 0;
            std::cout << "Votre animal n'est plus malade ! " << std::endl;
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


