#include "./includes/zoo.h"
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Zoo::Zoo(/* args */)
{
}

Zoo::~Zoo()
{
}

void Zoo::Menu()
{
    string choice;
    string player_name;
    string zoo_name;
    int number_of_round = 1;

    system("cls");
    cout << "*******************************" << endl;
    cout << "      	    ZOOLAND           " << endl;
    cout << "*******************************" << endl;
    cout << "\nBienvenue dans ZooLand !" << endl;
    cout << "\nIl s'agit d'un jeu de gestion en tour par tour d'un ZOO !\nCe simulateur de Zoo revisite est inpire par le celebre jeu ZOOTYCOON!" << endl;
    cout << "\nEnjoy !!" << endl;

    do
    {
        cout << "\n*******************************" << endl;
        cout << "      	    MENU            " << endl;
        cout << "\n Que souhaitez-vous faire ?" << endl;
        cout << "\nTapez 1: Lancez une partie." << endl;
        cout << "\nTapez 2: Fermez le programme.\n"
             << endl;
        cin >> choice;
    } while (choice != "1" && choice != "2");

    if (choice == "1")
    {
        // start the game with the "cycle" function

        cout << "\nEntrez votre pseudo : \n"
             << endl;
        cin >> player_name;
        cout << "\nBienvenue" << player_name << "!! Definissez le nom de votre Zoo : \n"
             << endl;
        cout << endl;
        cin >> zoo_name;
        cout << "\n"
             << player_name << "la construction de votre zoo : " << zoo_name << " peut commencer !" << endl;
        // 120 rounds = 10 years = 1 month per round
        // while (number_of_round != 120)
        // {

        //     // le

        //     // End of the day at the zoo
        //     number_of_round += 1;
        // }
    }
    else
    {
        // leave the game
    }
}

void Zoo::Delete_Animal(int type, int ID)
{
    switch (type)
    {
    case 1: // aigle
        for (int i = 0; i < m_Eagle_Habitats.size(); i++)
        {
            Animal_Sell result = m_Eagle_Habitats[i].Delete_Animal(ID);
            if (result.Sell_Check) {
                m_Budget.Sell_Something(result.Price);
                cout << "Votre animal a ete supprime !" << endl;
            }
        }

        break;
    case 2: // tigre
        
        break;
    case 3: // hen
       
        break;

    default:
        break;
    }

    cout << "ID inconnu, veuillez rentrer un ID correct la prochaine fois !" << endl;
}

void Zoo::Add_Animal(int type, int age, bool gender)
{
    // Function which will add an Animal according to the type : 1 for eagle, 2 for tiger, 3 for hen
    switch (type)
    {
    case 1:
    {
        Aigle New_Animal(gender, age, m_Eagle_ID);
        m_Eagle_ID++;

        for (int i = 0; i < m_Eagle_Habitats.size(); i++)
        {
            if (m_Eagle_Habitats[i].Add_Animal_In_Habitat(New_Animal))
            {
                cout << "Votre animal est bel et bien ajouté !" << endl;
                return;
            }
        }
        cout << "Votre animal est mort, car il n'a pas d'habitat. Veuillez acheter la prochaine fois ! " << endl;
    }
    break;
    case 2:
    {
        /* Define new Tiger */
    }
    break;
    case 3:
    {
        /* Define new Hen */
    }
    break;
    default:
        cout << "ERREUR LORS DE LA CREATION DE L'ANIMAL" << endl;
        break;
    }
}

void Zoo::Evenly_Buy_Animal()
{
    int Animal_Choice;
    int Sex_Choice;
    int Animal_Age;
    int confirm;
    cout << "Voulez vous acheter un tigre, un aigle, ou une poule/coq ?" << endl;
    do
    {
        cout << "Tapez 1 pour aigle, 2 pour tigre, 3 pour poule/coq : ";
        cin >> Animal_Choice;
    } while (Animal_Choice != 1 && Animal_Choice != 2 && Animal_Choice != 3);

    cout << "Vous avez choisi un " << Display_Good_Animal(Animal_Choice, 0, 0) << endl;

    if (Animal_Choice != 3)
    {
        cout << "Maintenant choisissons l'age de votre futur " << Display_Good_Animal(Animal_Choice, 0, 0) << endl;

        do
        {
            cout << "Tapez 1 pour 6 mois, 2 pour 4 ans, 3 pour 14 ans : ";
            cin >> Animal_Age;
        } while (Animal_Age != 1 && Animal_Age != 2 && Animal_Age != 3);

        switch (Animal_Age)
        {
        case 1:
            Animal_Age = 6;
            break;
        case 2:
            Animal_Age = 48;
            break;
        case 3:
            Animal_Age = 168;
            break;
        default:
            break;
        }
    }
    else
    {
        Animal_Age = 6;
    }

    cout << "Enfin, veuillez choisir le sexe de votre animal : " << endl;

    do
    {
        cout << "Tapez 1 pour male, 2 pour femelle : ";
        cin >> Sex_Choice;
    } while (Sex_Choice != 1 && Sex_Choice != 2);

    cout << "Super ! Ce sera donc " << Display_Good_Animal(0, Sex_Choice, 0) << endl;

    int price = Check_Price_Buy_Value(Animal_Choice, Animal_Age, Sex_Choice);
    cout << "Votre " << Display_Good_Animal(Animal_Choice, 0, 0) << " va donc couter " << price << " euros" << endl;
    do
    {
        cout << "Tapez 1 pour confirmer, 2 pour annuler : " << endl;
        cin >> confirm;
    } while (confirm != 1 && confirm != 2);

    if (confirm == 1)
    {
        cout << "Ajout de l'animal a votre enclos..." << endl;
        // m_Budget.Buy_Something(price);
        // Add_Animal(Animal_Choice, Animal_Age, Sex_Choice == 1)
        cout << "C'est" << Display_Good_Animal(0, Sex_Choice, 0) << " " << Display_Good_Animal(Animal_Choice, 0, 0) << " de " << Animal_Age << " mois" << endl;
        cout << "C'est fait !" << endl;
    }
    else
    {
        cout << "La transaction a ete annule" << endl
             << endl
             << endl;
    }
}

string Zoo::Display_Good_Animal(int Animal_Choice, int Sex_Choice, int Animal_Age)
{
    if (Animal_Choice != 0)
    {
        switch (Animal_Choice)
        {
        case 1:
            return "aigle";
            break;
        case 2:
            return "tigre";
            break;
        default: // = case 3
            return "coq/poule";
            break;
        }
    }
    else if (Sex_Choice != 0)
    {
        if (Sex_Choice == 1)
        {
            return "un male";
        }
        return "une femelle";
    }
    else
    {
        switch (Animal_Age)
        {
        case 6: // 6 ans
            return " 6 mois";
            break;
        case 48: // 4 ans
            return " 4 ans";
            break;
        case 168: // 14 ans
            return " 14 ans";
            break;
        default:
            break;
        }
    }

    return ""; // check error
}

int Zoo::Check_Price_Buy_Value(int type, int age, int sex)
// Return the value of potential achat of an animal with the age and evenly sex
{
    switch (type)
    {
    case 1:
        switch (age)
        {
        case 6:
            return 1000;
            break;
        case 48:
            return 4000;
            break;
        case 168:
            return 2000;
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (age)
        {
        case 6:
            return 3000;
            break;
        case 48:
            return 120000;
            break;
        case 168:
            return 60000;
            break;
        default:
            break;
        }
        break;
    case 3:
        if (sex == 1) // male
        {
            return 100;
        }
        else
        {
            return 20;
        }
        break;

    default:
        break;
    }

    return -1; // check error
}

void Zoo::Print_All_Animals()
{
    // Function which will display all the Animal on the Zoo
    for (int i = 0; i < m_Eagle_Habitats.size(); i++)
    {
        std::vector<Aigle> Current_Habitat = m_Eagle_Habitats[i].Get_All_Animals();
        for (int j = 0; j < Current_Habitat.size(); j++)
        {
            Current_Habitat[j].Print(); // Print informations about the animal
        }
    }

    // ! Print for Tiger
    for (int i = 0; i < m_Tiger_Habitats.size(); i++)
    {
        /* code */
    }

    // ! Print for eagle
    for (int i = 0; i < m_Hen_Habitats.size(); i++)
    {
        /* code */
    }
}

void Zoo::Evenly_Sell_Animal()
{
    int ID_Selected;
    int type;
    int confirm;

    cout << "Voici vos animaux : " << endl;
    Print_All_Animals();
    cout << "Quel type d'animal voulez vous vendre ?" << endl;
    do
    {
        cout << " Tapez 1 pour aigle, 2 pour tigre, 3 pour poule/coq : ";
        cin >> type;
    } while (type != 1 && type != 2 && type != 3);

    cout << "Selectionnez desormais l'ID de l'animal que vous voulez supprimer : " << endl;
    cin >> ID_Selected;

    do
    {
        cout << "Confirmer ? Appuyez 1 pour confirmer, 2 pour annuler" << endl;
    } while (confirm != 1 && confirm != 2);

    Delete_Animal(type, ID_Selected);
}

void Zoo::Evenly_Buy_Habitat()
{
}

void Zoo::Evenly_Sell_Habitat()
{
}
