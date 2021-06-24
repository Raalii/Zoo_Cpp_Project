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
    // . All variable IDs, to differentiate all animals
    int m_Eagle_ID = 0;
    int m_Tiger_ID = 0;
    int m_Hen_ID = 0;
    // . Define dynamic array of each Habitat 
    vector<Eagle_Habitat> m_Eagle_Habitats = vector<Eagle_Habitat>(0);
    vector<Tiger_Habitat> m_Tiger_Habitats = vector<Tiger_Habitat>(0);
    vector<Hen_Habitat> m_Hen_Habitats = vector<Hen_Habitat>(0);
    // . Game loop and variable to check the good unfolding of the game
    bool m_running;
    // . Budget
    Budget m_Budget;
    // . Food Quantity
    float m_Graine_Quantity = 0;
    float m_Viande_Quantity = 0;
    // . Variables to define time, high seasons...
    int total_Month = 0;
    int month = 1;
public:
    Zoo();
    ~Zoo();
    void Menu();
    void Update();
    void Evenly_Buy_Animal();
    void Evenly_Sell_Animal();
    void Evenly_Buy_Habitat();
    void Evenly_Sell_Habitat();
    void Add_Animal(int type, int age, bool gender);
    void Delete_Animal(int type, int ID );
    void Check_User_Action();
    void Random_Event();
    void Update_Malade_State();
    void Print_All_Animals();
    // void Print_Animal();
    bool Check_Season();
    int Check_Price_Buy_Value(int type, int age, int sex);
    string Display_Good_Animal(int Animal_Choice, int Sex_Choice, int Animal_Age);
};

#endif