#ifndef itemVector_hpp
#define itemVector_hpp


#include <stdio.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include "item.hpp"
using namespace std;
class itemVector{
private:
    vector<Item> item;
public:
    void setItem(Item i1);
    Item* getVectorItem();
    int getItemSize();
    void displayItemVector();
    void readItemFile(string path);
    void writeInventory(Item* item);
    Item* findItemRecord(string it);
};
#endif /* itemVector_hpp */
