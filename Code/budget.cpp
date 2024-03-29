#include "./includes/budget.h"
#include <iostream>

Budget::Budget(){
}

Budget::~Budget(){
}

void Budget::Capital_Check() {
    if (m_Capital < 0) {
        m_bankrupt = true;
        std::cout << "Votre solde est negatif ! Le prochain tour vous sera fatal..." << std::endl;
    } else {
        std::cout << "Il vous reste " << m_Capital << " euros ! " << std::endl;
    }
}

void Budget::Buy_Something(int price) {
    m_Capital -= price;
    Capital_Check();
};

void Budget::Sell_Something(int price) {
    m_Capital += price;
    std::cout << "Il vous reste " << m_Capital << " euros ! " << std::endl;
};

bool Budget::Get_Bankrupt() {
    return m_bankrupt;
}

void Budget::Add_Money_By_Subvention(int month, int Nbr_Tiger, int Nbr_Eagle)
{
    if (month == 12) // If the current month are december
    {
        // Subvention by the government to help the zoo. 43800$ for each tiger, and 2190$ for each eagle
        m_Capital += 43800.00 * Nbr_Tiger; // Add to the capital
        m_Capital += 2190.00 * Nbr_Eagle;
    }
}

void Budget::Money_Incomme_By_Visitors(int month, int Nbr_Tiger_Visible, int Nbr_Poule_Visible, int Nbr_Eagle_Visible)
{
    int Nbr_Visitors = 0;
    if (month >= 5 && month <= 9) // if we are in peak season
    {
        // Number Of days in a month * number of visitors for an animal in peak season * number of animal
        Nbr_Visitors += round(30.00 * Nbr_Tiger_Visible);
        Nbr_Visitors += round(2.0 * Nbr_Poule_Visible);
        Nbr_Visitors += round(15.00 * Nbr_Eagle_Visible);
    }
    else
    {
        Nbr_Visitors += round(5 * Nbr_Tiger_Visible);
        Nbr_Visitors += round(0.5 * Nbr_Poule_Visible);
        Nbr_Visitors += round(7 * Nbr_Eagle_Visible);
    }

    m_Capital += Nbr_Visitors * ((17 * 2) + (13 * 2)); // Two childrens and two Adults in one visit (17$ for Adults, 13$ for children)
}


float Budget::Get_Capital() {
    return m_Capital;
}


// ! Achat/Vente habitat  
// ! Achat nourriture 
// ! Achat/Vente animaux 