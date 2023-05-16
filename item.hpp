#ifndef item_hpp
#define item_hpp
#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
class Item{
private:
    string itemName;
    int newHealth;
    int newLife;
    int newDamage;
public:
    Item();
    Item(string tempItemName, int tempNewHealth, int tempNewLife, int tempNewDamage);
    string getItemName();
    int getNewHealth();
    int getNewLife();
    int getNewDamage();
    void setItemName(string tempItemName);
    void setNewHealth( int tempNewHealth);
    void setNewLife( int tempNewLife);
    void setNewDamage( int tempNewDamage);
};
#endif /* item_hpp */
