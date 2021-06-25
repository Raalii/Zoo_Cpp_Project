#include "./includes/habitat.h"
std::default_random_engine new_re(time(0));             // Depend of time to simulate random tirage
std::uniform_int_distribution<int> male_or_female{1, 0};
std::uniform_int_distribution<int> new_distrib{0, 100};
// . Habitat : principal class

Habitat::Habitat()
{
}

Habitat::~Habitat()
{
}

/***************************************************************

// . EAGLE HABITAT CLASS

***************************************************************/

Eagle_Habitat::Eagle_Habitat()
{
    m_Capacity = 4;
}

Eagle_Habitat::~Eagle_Habitat()
{
}

Animal_Sell Eagle_Habitat::Delete_Animal(int ID)
// Function which will delete an animal in this habitat. That permitte to manage habitat (change, delete...).
{
    Animal_Sell Is_Sell;
    for (size_t i = 0; i < m_Current_Habitat.size(); i++)
    {
        if (ID == m_Current_Habitat[i].Get_ID())
        {
            Is_Sell.Price = m_Current_Habitat[i].CheckPriceValue();
            m_Current_Habitat[i], m_Current_Habitat[m_Current_Habitat.size() - 1] = m_Current_Habitat[m_Current_Habitat.size() - 1], m_Current_Habitat[i];
            m_Current_Habitat.pop_back();
            Is_Sell.Sell_Check = true;
            return Is_Sell;
        }
    }

    Is_Sell.Sell_Check = false;
    Is_Sell.Price = 0;
    return Is_Sell;
}

int Eagle_Habitat::Get_ID()
{
    return m_ID;
}

bool Eagle_Habitat::Add_Animal_In_Habitat(Aigle Current_Animal)
// Function which will add an animal in this Habitat, return false if is not possible (over-capacity)
{
    if (m_Current_Habitat.size() < m_Capacity * 2)
    {
        m_Current_Habitat.push_back(Current_Animal);
        return true;
    }
    else
    {
        return false;
    }
}

void Eagle_Habitat::Print()
{
    std::cout << "---------------------" << std::endl;
    std::cout << "ID de l'habitat : " << m_ID << std::endl;
    std::cout << "Nombre d'animaux : " << m_Current_Habitat.size() << std::endl;
    std::cout << "Capacite : " << m_Capacity << std::endl;
    std::cout << "Details sur les animaux : " << std::endl;
    for (int i = 0; i < m_Current_Habitat.size(); i++)
    {
        m_Current_Habitat[i].Print();
    }
    std::cout << "---------------------" << std::endl;
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

void Eagle_Habitat::Edit_Reproduce()
{
    int male = 0;
    int female = 0;
    Aigle a_male;
    Aigle a_female;
    for (int i = 0; i < m_Current_Habitat.size(); i++)
    {
        if (m_Current_Habitat[i].Get_Gender() && m_Current_Habitat[i].Can_Reproduce(Is_Surpopulation()))
        {
            male++;
            a_male = m_Current_Habitat[i];
        }
        else if (!m_Current_Habitat[i].Get_Gender() && m_Current_Habitat[i].Can_Reproduce(Is_Surpopulation()))
        {
            female++;
            a_female = m_Current_Habitat[i];
        }
    }

    if (male > 0 && female > 0)
    {
        a_female.Start_Reproduction();
    }
}

void Eagle_Habitat::Edit_Maladie()
{
    for (int i = 0; i < m_Current_Habitat.size(); i++)
    {
        if (m_Current_Habitat[i].Update_Malade(Is_Surpopulation())) {
            Delete_Animal(m_Current_Habitat[i].Get_ID());
        } 
    }
}

void Eagle_Habitat::Born(int New_ID) {
    Aigle baby(1 == male_or_female(new_re), 1, New_ID);
    if (new_distrib(new_re) < 50)
    {
        std::cout << "le bebe a malheuresement peri !" << std::endl;
    } else {
        std::cout << "le bebe aigle est enfin nee !" << std::endl;
        Add_Animal_In_Habitat(baby);
    }
}

// void Eagle_Habitat::

/***************************************************************

// . TIGER HABITAT CLASS

***************************************************************/

Tiger_Habitat::Tiger_Habitat()
{
    m_Capacity = 2;
}

Tiger_Habitat::~Tiger_Habitat()
{
}

Animal_Sell Tiger_Habitat::Delete_Animal(int ID)
// Function which will delete an animal in this habitat. That permitte to manage habitat (change, delete...).
{
    Animal_Sell Is_Sell;
    for (size_t i = 0; i < m_Current_Habitat.size(); i++)
    {
        if (ID == m_Current_Habitat[i].Get_ID())
        {
            Is_Sell.Price = m_Current_Habitat[i].CheckPriceValue();
            m_Current_Habitat[i], m_Current_Habitat[m_Current_Habitat.size() - 1] = m_Current_Habitat[m_Current_Habitat.size() - 1], m_Current_Habitat[i];
            m_Current_Habitat.pop_back();
            Is_Sell.Sell_Check = true;
            return Is_Sell;
        }
    }

    Is_Sell.Sell_Check = false;
    Is_Sell.Price = 0;
    return Is_Sell;
}

int Tiger_Habitat::Get_ID()
{
    return m_ID;
}

bool Tiger_Habitat::Add_Animal_In_Habitat(Tigre Current_Animal)
// Function which will add an animal in this Habitat, return false if is not possible (over-capacity)
{
    if (m_Current_Habitat.size() < m_Capacity * 2)
    {
        m_Current_Habitat.push_back(Current_Animal);
        return true;
    }
    else
    {
        return false;
    }
}

void Tiger_Habitat::Print()
{
    std::cout << "---------------------" << std::endl;
    std::cout << "ID de l'habitat : " << m_ID << std::endl;
    std::cout << "Nombre d'animaux : " << m_Current_Habitat.size() << std::endl;
    std::cout << "Capacite : " << m_Capacity << std::endl;
    std::cout << "Details sur les animaux : " << std::endl;
    for (int i = 0; i < m_Current_Habitat.size(); i++)
    {
        m_Current_Habitat[i].Print();
    }
    std::cout << "---------------------" << std::endl;
}

std::vector<Tigre> Tiger_Habitat::Get_All_Animals()
// Function which return the list of animal present in this Habitat
{
    return m_Current_Habitat;
}

bool Tiger_Habitat::Is_Surpopulation()
// Check if the animal are in surpopulation
{
    return m_Capacity < m_Current_Habitat.size();
}

void Tiger_Habitat::Edit_Reproduce()
{
    int male = 0;
    int female = 0;
    Tigre a_male;
    Tigre a_female;
    for (int i = 0; i < m_Current_Habitat.size(); i++)
    {
        if (m_Current_Habitat[i].Get_Gender() && m_Current_Habitat[i].Can_Reproduce(Is_Surpopulation()))
        {
            male++;
            a_male = m_Current_Habitat[i];
        }
        else if (!m_Current_Habitat[i].Get_Gender() && m_Current_Habitat[i].Can_Reproduce(Is_Surpopulation()))
        {
            female++;
            a_female = m_Current_Habitat[i];
        }
    }

    if (male > 0 && female > 0)
    {
        a_female.Start_Reproduction();
    }
}

void Tiger_Habitat::Edit_Maladie()
{
    for (int i = 0; i < m_Current_Habitat.size(); i++)
    {
        if (m_Current_Habitat[i].Update_Malade(Is_Surpopulation())) {
            Delete_Animal(m_Current_Habitat[i].Get_ID());
        }
    }
}

void Tiger_Habitat::Born(int New_ID) {
    Tigre baby(1 == male_or_female(new_re), 1, New_ID);
    if (new_distrib(new_re) < 50)
    {
        std::cout << "le bebe a malheuresement peri !" << std::endl;
    } else {
        std::cout << "le bebe tigre est enfin nee !" << std::endl;
        Add_Animal_In_Habitat(baby);
    }
}

/***************************************************************

// . HEN HABITAT CLASS

***************************************************************/

Hen_Habitat::Hen_Habitat(/* args */)
{
    m_Capacity = 10;
}

Hen_Habitat::~Hen_Habitat()
{
}

Animal_Sell Hen_Habitat::Delete_Animal(int ID)
// Function which will delete an animal in this habitat. That permitte to manage habitat (change, delete...).
{
    Animal_Sell Is_Sell;
    for (size_t i = 0; i < m_Current_Habitat.size(); i++)
    {
        if (ID == m_Current_Habitat[i].Get_ID())
        {
            Is_Sell.Price = m_Current_Habitat[i].CheckPriceValue();
            m_Current_Habitat[i], m_Current_Habitat[m_Current_Habitat.size() - 1] = m_Current_Habitat[m_Current_Habitat.size() - 1], m_Current_Habitat[i];
            m_Current_Habitat.pop_back();
            Is_Sell.Sell_Check = true;
            return Is_Sell;
        }
    }

    Is_Sell.Sell_Check = false;
    Is_Sell.Price = 0;
    return Is_Sell;
}

int Hen_Habitat::Get_ID()
{
    return m_ID;
}

bool Hen_Habitat::Add_Animal_In_Habitat(Poule Current_Animal)
// Function which will add an animal in this Habitat, return false if is not possible (over-capacity)
{
    if (m_Current_Habitat.size() < m_Capacity * 2)
    {
        m_Current_Habitat.push_back(Current_Animal);
        return true;
    }
    else
    {
        return false;
    }
}

void Hen_Habitat::Print()
{
    std::cout << "---------------------" << std::endl;
    std::cout << "ID de l'habitat : " << m_ID << std::endl;
    std::cout << "Nombre d'animaux : " << m_Current_Habitat.size() << std::endl;
    std::cout << "Capacite : " << m_Capacity << std::endl;
    std::cout << "Details sur les animaux : " << std::endl;
    for (int i = 0; i < m_Current_Habitat.size(); i++)
    {
        m_Current_Habitat[i].Print();
    }
    std::cout << "---------------------" << std::endl;
}

std::vector<Poule> Hen_Habitat::Get_All_Animals()
// Function which return the list of animal present in this Habitat
{
    return m_Current_Habitat;
}

bool Hen_Habitat::Is_Surpopulation()
// Check if the animal are in surpopulation
{
    return m_Capacity < m_Current_Habitat.size();
}

void Hen_Habitat::Edit_Reproduce()
{
    int male = 0;
    int female = 0;
    Poule a_male;
    Poule a_female;
    for (int i = 0; i < m_Current_Habitat.size(); i++)
    {
        if (m_Current_Habitat[i].Get_Gender() && m_Current_Habitat[i].Can_Reproduce(Is_Surpopulation()))
        {
            male++;
            a_male = m_Current_Habitat[i];
        }
        else if (!m_Current_Habitat[i].Get_Gender() && m_Current_Habitat[i].Can_Reproduce(Is_Surpopulation()))
        {
            female++;
            a_female = m_Current_Habitat[i];
        }
    }

    if (male > 0 && female > 0)
    {
        a_female.Start_Reproduction();
    }
}

void Hen_Habitat::Edit_Maladie()
{
    for (int i = 0; i < m_Current_Habitat.size(); i++)
    {
       if (m_Current_Habitat[i].Update_Malade(Is_Surpopulation())) {
            Delete_Animal(m_Current_Habitat[i].Get_ID());
        }
    }
}

void Hen_Habitat::Born(int New_ID) {
    Poule baby(1 == male_or_female(new_re), 1, New_ID);
    if (new_distrib(new_re) < 50)
    {
        std::cout << "le bebe a malheuresement peri !" << std::endl;
    } else {
        std::cout << "le bebe tigre est enfin nee !" << std::endl;
        Add_Animal_In_Habitat(baby);
    }
}