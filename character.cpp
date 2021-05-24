#include <iostream>
#include <string>
using namespace std;

class Character {
    private: 
        string abilities[6] = {"Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"};
        int abilityScores[6] = {};
        string fName = "Leeroy";
        string lName = "Jenkins";

    public:
    string * getAbilities(){
        return abilities;
    } 

    int * getAbilityScores(){
        return abilityScores;
    }

    void setAbilityScores(int *organizedScores){
        for(int i = 0; i < 6; i++){
            abilityScores[i] = organizedScores[i];
        }
    }

    void setName(){
        cout << "What is your adventurer's first name?\n";
        string firstName;
        cin >> firstName;
        fName = firstName;
        
        cout << "What is your adventurer's last name?\n";
        string lastName;
        cin >> lastName;
        lName = lastName;
    }

    string getFName(){
        return fName;
    }

    string getLName(){
        return lName;
    }

    void printCharacterToConsole(){
        cout << "Adventurer's Name: "<< fName << " " << lName << "\n";
        for(int i = 0; i < 6; i++) {
            cout << abilities[i] << ": " << abilityScores[i] << "\n";
        }
    }
};