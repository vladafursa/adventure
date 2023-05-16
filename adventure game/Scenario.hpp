#ifndef Scenario_hpp
#define Scenario_hpp

#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
class Story{
private:
    string current;
    string description;
    string question;
    string branch1;
    string branch2;
    string item;
    string enemy;
    int addedLives;
    int addedHealth;
    int addedDamage;
    int addedScore;
public:
    string getCurrent();
    string getDescription();
    string getQuestion();
    string getBranch1();
    string getBranch2();
    string getItem();
    string getEnemy();
    int getAddedLives();
    int getAddedHealth();
    int getAddedDamage();
    int getAddedScore();
    void setCurrent(string tempCurrent);
    void setDescription(string tempDescription);
    void setQuestion(string tempQuestion);
    void setBranch1(string tempBranch1);
    void setBranch2(string tempBranch2);
    void setItem(string tempItem);
    void setEnemy(string tempEnemy);
    void setAddedLives(int tempAddedLives);
    void setAddedHealth(int tempAddedHealth);
    void setAddedDamage(int tempAddedDamage);
    void setAddedScore(int tempAddedScore);
    Story();
    Story(string tempCurrent,string tempDescription, string tempQuestion, string tempBranch1,string tempBranch2, int tempAddedLives, int tempAddedHealth, int tempAddedDamage, int tempAddedScore, string tempItem, string tempEnemy);
};

#endif /* Scenario_hpp */
