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
