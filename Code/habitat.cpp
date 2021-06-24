#include "./includes/habitat.h"

//il faut le type d'habitat : tigre , aigle, poule
// il faut le prix par habitat

// il faut ensuite stocker le nombre d'habitat que l'utilisateur possède

// . Habitat : principal class

Habitat::Habitat()
{
}

Habitat::~Habitat()
{
}

// . EAGLE HABITAT CLASS

Eagle_Habitat::Eagle_Habitat()
{
    m_Capacity = 4;
}

Eagle_Habitat::~Eagle_Habitat()
{
}

void Eagle_Habitat::Delete_Animal(int ID)
// Function which will delete an animal in this habitat. That permitte to manage habitat (change, delete...).
{
    for (size_t i = 0; i < m_Current_Habitat.size(); i++)
    {
        if (ID == m_Current_Habitat[i].Get_ID())
        {
            m_Current_Habitat[i], m_Current_Habitat[m_Current_Habitat.size() - 1] = m_Current_Habitat[m_Current_Habitat.size() - 1], m_Current_Habitat[i];
            m_Current_Habitat.pop_back();
        }
    }
}

bool Eagle_Habitat::Add_Animal_In_Habitat(Aigle Current_Animal)
// Function which will add an animal in this Habitat, return true if the function 
{
    if (m_Current_Habitat.size() < m_Capacity * 2)
    {
        m_Current_Habitat.push_back(Current_Animal);
        return true;
    } else {
        return false;
    }
}

std::vector<Aigle> Eagle_Habitat::Get_All_Animals()
// Function which return the list of animal present in this Habitat
{
    return m_Current_Habitat;
}

bool Eagle_Habitat::Is_Surpopulation()
    // Check if the animal are in surpopulation
{
    return m_Capacity < m_Current_Habitat.size();   
}

// . TIGER HABITAT CLASS

Tiger_Habitat::Tiger_Habitat()
{
    m_Capacity = 2;
}

Tiger_Habitat::~Tiger_Habitat()
{
}

// . HEN HABITAT CLASS

Hen_Habitat::Hen_Habitat(/* args */)
{
}

Hen_Habitat::~Hen_Habitat()
{
}
