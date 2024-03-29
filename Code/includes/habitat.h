#ifndef HABITAT_H
#define HABITAT_H

// #include <iostream>
// // #include "zoo.h"
// // #include "int.h"
#include "aigle.h"
#include "tigre.h"
#include "poule.h"
#include <string>
#include <vector>


struct Animal_Sell
{
    bool Sell_Check;
    float Price;
};


// using namespace std;

/*
 * 
 * 
 * 
 . HABITAT  
 * 
 * 
 *  
*/

class Habitat
{
protected:
    int m_Capacity = -1; // if the class are not defined, the default value are -1.
public:
    Habitat();
    Habitat(int Capacity);
    ~Habitat();
};

/*
 * 
 * 
 * 
 . AIGLE HABITAT  
 * 
 * 
 *  
*/

class Eagle_Habitat : public Habitat
{
private:
    int m_ID;
    std::vector<Aigle> m_Current_Habitat = std::vector<Aigle>(0);

public:
    Eagle_Habitat(/* args */);
    Eagle_Habitat(int ID);
    ~Eagle_Habitat();
    Animal_Sell Delete_Animal(int ID);
    bool Add_Animal_In_Habitat(Aigle Current_Animal);
    std::vector<Aigle> Get_All_Animals();
    int Get_ID();
    void Print();
    bool Is_Surpopulation();
    void Edit_Reproduce();
    void Edit_Maladie();
    void Edit_Food();
    void Born(int New_ID);
    void Edit_Age();
};

/*
 * 
 * 
 * 
 . TIGRE HABITAT  
 * 
 * 
 *  
*/

class Tiger_Habitat : public Habitat
{
private:
    int m_ID;
    std::vector<Tigre> m_Current_Habitat = std::vector<Tigre>(0);
public:
    Tiger_Habitat();
    Tiger_Habitat(int ID);
    ~Tiger_Habitat();
    Animal_Sell Delete_Animal(int ID);
    bool Add_Animal_In_Habitat(Tigre Current_Animal);
    std::vector<Tigre> Get_All_Animals();
    int Get_ID();
    void Print();
    bool Is_Surpopulation();
    void Edit_Reproduce();
    void Edit_Maladie();
    void Born(int New_ID);
    void Edit_Age();
};

/*
 * 
 * 
 * 
 . HEN HABITAT  
 * 
 * 
 *  
*/

class Hen_Habitat : public Habitat
{
private:
    int m_ID;
    std::vector<Poule> m_Current_Habitat = std::vector<Poule>(0);

public:
    Hen_Habitat();
    Hen_Habitat(int ID);
    ~Hen_Habitat();
    Animal_Sell Delete_Animal(int ID);
    bool Add_Animal_In_Habitat(Poule Current_Animal);
    std::vector<Poule> Get_All_Animals();
    int Get_ID();
    void Print();
    bool Is_Surpopulation();
    void Edit_Reproduce();
    void Edit_Maladie();
    void Born(int New_ID);
    void Edit_Age();
};

#endif