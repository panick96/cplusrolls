#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>

using namespace std;

class Roll {
    private:
        //Roll attributes
        int rolls[6];
        int organizedRolls[6];
    
    public:
    void rollDice(){
        //Rolls 4 6d dice and keeps the highest 3.

        //Create a temporary array to hold rolls.
        int rolledDice[4];

        //Creates a seed for rand().
        srand (time(NULL));
        int sum = 0;

        //Nested for loop for rolling for all 6 ability scores.
        for(int i = 0; i < 6; i++){    
            for(int j = 0; j < 4; j++){
                rolledDice[j] = rand() % 6 + 1;
            }
            sort(rolledDice, rolledDice + 4);   
            for (int j = 1; j < 4; j++){
                sum += rolledDice[j];
            }
            rolls[i] = sum;
            sum = 0;
        }
        cout << "Rolling...\n";
    }
    void promptOrganizeRolls(string *abilities) {
        cout << "Set your ability scores\n";
        for(int i = 0; i < 6; i++){
            cout << i + 1 << ". " << abilities[i] << "\n";
            for(int j = 0; j <6; j++){
                if(j < 5){
                    cout << rolls[j] << ", ";
                } else {
                    cout << rolls[j] << "\n";
                }}
            int input;
            cin >> input;
            bool exists = find(begin(rolls), end(rolls), input) != end(rolls);
            while((exists == false) or(input < 3)){
                cout << "Please choose one of your rolls\n"; 
                for(int j = 0; j <6; j++){
                if(j < 5){
                    cout << rolls[j] << ", ";
                } else {
                    cout << rolls[j] << "\n";
                }}
                cin >> input;
                exists = find(begin(rolls), end(rolls), input) != end(rolls);
            }
            auto findIndex = find(begin(rolls), end(rolls), input);
            int indexToChange = findIndex - begin(rolls);
            organizedRolls[i] = input;
            rolls[indexToChange] = 0;
        }
    }
    int * getOrganizedRolls() {
        return organizedRolls;
    }
};