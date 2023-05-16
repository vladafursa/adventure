#ifndef ScenarioVector_hpp
#define ScenarioVector_hpp

#include <stdio.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "enemyVector.hpp"
#include "player.hpp"
#include "Scenario.hpp"
#include "itemVector.hpp"
//Forward declaration of class
class Gameplay;
class StoryVector{
private:
    vector<Story> story;
    //default player
    Player player{3, 100, 20, 0};
    //Pointer to object of class
    Gameplay* Game1;
    itemVector item;
    enemyVector enemy;
public:
    StoryVector(Gameplay* Game1_ptr);
    ~StoryVector();
    void setVectorItem(Story s1);
    Story* getVector();
    int getSize();
    void displayStoryVector();
    void readFile();
    Story* findRecord();
    void writeToFile(Story* pointer);
    void writeToDescriptionFile(string currentDescription);
    string findCurrent();
    void deleteLastLine();
    string loadFullDescription();
    void clear(string filename);
    void clearCurrentStats();
};
#endif /* ScenarioVector_hpp */
