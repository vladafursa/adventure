#ifndef player_hpp
#define player_hpp
#include "character.hpp"
#include "enemy.hpp"
#include "item.hpp"
#include <vector>
#include<iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include <stdio.h>
class Player:public Character{
private:
    int score;
    vector<Item> inventory;
    
public:
    int getScore();
    void setScore(int tempScore);
    ~Player();
    Player();
    Player(int tempLives, int tempHealth, int tempDamage, int tempScore);
    void display();
    void collectItem(Item* item);
    void displayCollectedItem(Item* item);
    Item* getInventoryVector();
    void setDataFromFile();
    void writeStats(int parselives, int parseHealth, int parseDamage, int parseScore);
    void combat(Enemy* enemy);
    void changeStats(int addLives, int addHealth, int addDamage, int addScore);
    void additionalFinal();
};
#endif /* player_hpp */
