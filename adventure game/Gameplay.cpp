#include "Gameplay.hpp"
#include <iostream>
#include "Scenario.hpp"
#include "ScenarioVector.hpp"
#include "player.hpp"
using namespace std;
// Create an object of class
Gameplay::Gameplay(){
    v=new StoryVector(this);
}
//destructor
Gameplay::~Gameplay(){
    delete v;
}
//getters
bool Gameplay::getAction(){
    return action;
}
int Gameplay::getChoice(){
    return choice;
}
//setters
void Gameplay::setAction(bool tempAction){
    action=tempAction;
}
void Gameplay::setChoice(int tempChoice){
    choice = tempChoice;
}
//checking if input is number
int Gameplay::getNumber(){
    bool loop=true;
    string number;
    while(loop==true){
        cout<<"Please type in your choice: "<<endl;
        getline(cin, number);
        for(int i=0;i<number.length();i++){
            if(isdigit(number[i])!=true){
            cout<<"input should be a number"<<endl;
            return getNumber();
            }
        }
        loop =false;
    }
    return stoi(number);
}
//display menu with asking for choice and error checking
int Gameplay::displayMenu(){
    int tempChoice;
    bool valid = false;
    do{
        cout<<"Please make a choice: "<<endl;
        cout<<"1 - start a new game"<<endl;
        cout<<"2 - resume"<<endl;
        cout<<"3 - exit"<<endl;
        tempChoice=getNumber();
        if (tempChoice >0 and tempChoice<=3){
            valid = true;
        }
        else{
            cout<<"please type in valid choice: ";
        }
    }while(valid==false);
    setChoice(tempChoice);
    return getChoice();
}
//work of the game
void Gameplay::Menu(int choice){
    while(action==true){
        switch(choice){
            case 1:
                //clear old data from previous game
                v->clear("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/currentScenario.txt");
                v->clear("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/currentStats.txt");
                v->clear("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/inventory.txt");
               // v->clear("currentScenario.txt");
               // v->clear("currentStats.txt");
               // v->clear("inventory.txt");
                v->readFile();
                v->findRecord();
                break;
            case 2:
                v->readFile();
                v->findRecord();
                break;
            case 3:
                setAction(false);
                break;
               
                }
        }
}
    

