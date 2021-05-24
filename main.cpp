#include <iostream>
#include "character.cpp"
#include "roll.cpp"
using namespace std;

int main() {
    Character charObj;
    Roll rollObj;
    cout << "Welcome to the DnD Character Calculator\n";
    cout << "Here you will set your ability points and name your character.\n";
    cout << "How exciting!\n";
    cout << "\n The abilities you are rolling for:\n";
    string * abilities = charObj.getAbilities();
    for(int i = 0; i < 6; i++){
        cout << i + 1 << "." << abilities[i] << "\n";
    }
    cout << "-----------------\n";
    rollObj.rollDice();
    rollObj.promptOrganizeRolls(charObj.getAbilities());
    charObj.setAbilityScores(rollObj.getOrganizedRolls());
    charObj.setName();
    cout << "-----------------\n";
    charObj.printCharacterToConsole();
    return 0;
}