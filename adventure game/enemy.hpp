#ifndef enemy_hpp
#define enemy_hpp

#include <stdio.h>
#include<iostream>
#include"character.hpp"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
class Enemy:public Character{
private:
    string name;
public:
    Enemy();
    string getName();
    void setName(string tempName);
    ~Enemy();
    Enemy(string tempName, int tempLives, int tempHealth, int tempDamage);
    void display();
};
#endif /* enemy_hpp */
