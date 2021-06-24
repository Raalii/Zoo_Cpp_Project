#include "./includes/Animal.h"

// #include "./includes/aigle.h"
// #include "./includes/tigre.h"
// #include "./includes/poule.h"

// Prepare random enironnment
std::default_random_engine re(time(0));             // Depend of time to simulate random tirage
std::uniform_int_distribution<int> distrib{0, 100}; // Number can be between 0 and 100
// -----------------------------------------------------------------------------------

Animal::Animal(/* args */)
{
}

// overload the constructor
Animal::Animal(bool gender, int age) : m_Gender(gender)
{
    m_State.s_Age.Current_Age = age;
}

Animal::~Animal()
{
}

/* 


. MALADIE STATE


*/

void Animal::CheckMaladie(int Probability)
{
    int prob = distrib(re);
    // std::cout << prob << std::endl;
    if (prob < Probability) // if the random value (0-100) returned are inferior than Probability (=Probability% of chance)
    {
        m_State.s_Malade.Is_Malade = true;
        std::cout << "Votre animal est malade " << std::endl;
    }
}

void Animal::Update_Malade(bool Is_Surpopulation)
{
    if (m_State.s_Malade.Is_Malade)
    {
        if (m_State.s_Malade.Max_Days <= m_State.s_Malade.days)
        {
            m_State.s_Malade.Is_Malade = false;
            m_State.s_Malade.days = 0;
            std::cout << "Votre animal n'est plus malade ! " << std::endl;
        }
        else
        {
            m_State.s_Malade.days += 30;
            // std::cout << m_State.s_Malade.Max_Days << std::endl;

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
        if (Is_Surpopulation)
        {
            CheckMaladie(50); // 50% chance to be Malade with surpopulation
        }
        CheckMaladie(30); // 30% chance to be Malade
    }
}

/* 


. HUNGRY STATE


*/

void Animal::Update_Hungry()
{
    m_State.s_Hungry.Days_Without_Food += 1;

    if (m_State.s_Hungry.Is_Hungry && m_State.s_Hungry.Days_Without_Food == m_State.s_Hungry.Max_Days * 2) // for instance 10 days to be hungry, and 20 to died.
    {
        // * Supprimer l'Animal
        std::cout << "Votre Animal est mort de faim ! " << std::endl;
    }
    else
    {
        if (m_State.s_Hungry.Days_Without_Food == m_State.s_Hungry.Max_Days) // If the days before the hungry state are atteigned
        {
            std::cout << "Votre Animal a faim ! " << std::endl;
            m_State.s_Hungry.Is_Hungry = true; // Animal are Hungry
        }
    }
}

void Animal::Reset_Hungry()
{
    m_State.s_Hungry.Is_Hungry = false;
    m_State.s_Hungry.Days_Without_Food = 0;
}

string Animal::Get_Type_Of_Food()
{
    return m_Type_Of_Food;
}

float Animal::Get_Food_Quantity()
{
    return m_Food_Quantity;
}

/* 


. REPRODUCTION STATE


*/

bool Animal::Can_Reproduce()
// Function which check if the animal can reproduce or not
{
    // If the Animal are Malade, Hungry, not in sexual period, New or already in reproduction, that return true. Else he return false.
    return m_State.s_Hungry.Is_Hungry || m_State.s_Age.Current_Age < m_State.s_Age.Sexual_Maturity || m_State.s_Age.Current_Age >= m_State.s_Age.Limite_Reproduction || m_State.s_Malade.Is_Malade || m_State.s_Reproduction.Is_Newer || m_State.s_Reproduction.Is_Reproduction;
}

bool Animal::Get_Is_Reproduction()
{
    return m_State.s_Reproduction.Is_Reproduction;
}

void Animal::Reset_Reproduction()
// Reset the state reproduction of the animal
{
    m_State.s_Reproduction.days = 0;
    m_State.s_Reproduction.Is_Reproduction = false;
}

bool Animal::Update_Reproduction()

/* This function will be update the reproduction state, when the animal are in gestation. 
   Return true if the baby will born, and false for others cases */
{
    m_State.s_Reproduction.days += 30;
    if (m_State.s_Hungry.Is_Hungry)
    {
        Reset_Reproduction();
        std::cout << "Le bebe a ete avorte !" << std::endl;
    }
    else
    {
        if (m_State.s_Reproduction.Reproduction_Duration <= m_State.s_Reproduction.days) // if the reproduction exceed the gestation period
        {
            Reset_Reproduction();
            return true; // The animal will be born
        }
    }

    return false;
}


/* 


. AGE STATE


*/

void Animal::Update_Age() {
    m_State.s_Age.Current_Age += 1;

    if (m_State.s_Age.Current_Age >= m_State.s_Age.Life_Esperance)
    {
        /* SUPPRIMER ANIMAL */
    } 
}

