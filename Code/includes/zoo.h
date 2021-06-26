#ifndef ZOO_H
#define ZOO_H

#include "budget.h"
#include "Animal.h"
#include "habitat.h"

using std::vector;
class Zoo
{
private:
    // . Personnalizable informations (name of the zoo, pseudo...)
    string m_nickname;
    string m_Zoo_nickname;
    // . All variable IDs, to differentiate all animals and All habitat
    int m_Eagle_ID = 0;
    int m_Tiger_ID = 0;
    int m_Hen_ID = 0;
    int m_Hen_Habitat_ID = 0;
    int m_Tiger_Habitat_ID = 0;
    int m_Eagle_Habitat_ID = 0;
    // . Define dynamic array of each Habitat 
    vector<Eagle_Habitat> m_Eagle_Habitats = vector<Eagle_Habitat>(0);
    vector<Tiger_Habitat> m_Tiger_Habitats = vector<Tiger_Habitat>(0);
    vector<Hen_Habitat> m_Hen_Habitats = vector<Hen_Habitat>(0);
    // . Budget
    Budget m_Budget;
    // . Food Quantity
    float m_Graine_Quantity = 0;
    float m_Viande_Quantity = 0;
    // . Variables to define time, high seasons...
    int m_total_Month = 0;
    int m_month = 1;
    // . Variable to notify the users for news of the month
    int m_born = 0;
    int m_died = 0;
    int m_depense = 0;
    int m_money_entry = 0;
public:
    Zoo();
    ~Zoo();
    void Menu();
    // . Actions functions
    void Evenly_Buy_Animal();
    void Evenly_Sell_Animal();
    void Evenly_Buy_Habitat();
    void Evenly_Sell_Habitat();
    void Evenly_Buy_Food();
    void Delete_Animal(int type, int ID );
    void Add_Animal(int type, int age, bool gender);
    bool Delete_Habitat(int type, int ID);
    void Buy_Something(int price);
    void Random_Event();
    void Print_All_Animals();
    int Total_Animal(int type, bool visible);
    void Evenly_Tidy_Animal();
    // void Print_Animal();
    bool Check_Season();
    int Check_Price_Buy_Value(int type, int age, int sex);
    string Display_Good_Animal(int Animal_Choice, int Sex_Choice, int Animal_Age);
    // . Game loop function to check the good unfolding of the game
    void Update_All_Animal_Reproduction_State();
    void Update_All_Animal_Maladie_State();
    void Update_All_Animal_Hungry_State();
    void Update_Month();
    void Game_Loop();
    void Turn_Menu();
    void Notification();
    void Update_All_Animal_Age_State();
    void Exceptionnal_Event();
};

#endif