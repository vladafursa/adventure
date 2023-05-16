#ifndef Gameplay_hpp
#define Gameplay_hpp
#include <stdio.h>
#include"character.hpp"
#include"enemy.hpp"
#include"player.hpp"
#include <ctime>
#include <stdlib.h>
// Forward declaration of class
class StoryVector;
class Gameplay{
private:
    int choice;
    bool action=true;
    // Pointer to object of class
    StoryVector* v;
public:
    Gameplay();
    ~Gameplay();
    bool getAction();
    void setAction(bool tempAction);
    int getChoice();
    void setChoice(int tempChoice);
    int displayMenu();
    void Menu(int choice);
    int getNumber();
    
};
#endif /* Gameplay_hpp */
