// #include <iostream>
#ifndef BUDGET_H
#define BUDGET_H

#include <cmath>
// #include "habitat.h"


class Budget {
    private:
        float m_Capital = 80000;
        bool m_bankrupt = false; //Variable for whether user is bankrupt or not
    public:
        Budget();
        ~Budget();
        void Add_Money_By_Subvention(int month, int Nbr_Tiger, int Nbr_Eagle);
        void Money_Incomme_By_Visitors(int month, int Nbr_Tiger, int Nbr_Poule, int Nbr_Eagle);
        float Get_Capital();
        bool Get_Bankrupt();
        void Buy_Something(int price);
        void Sell_Something(int price);
        void Capital_Check();
};




#endif
