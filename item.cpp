#include "item.hpp"
//getters
string Item::getItemName(){
    return itemName;
}
int Item::getNewHealth(){
    return newHealth;
}
int Item::getNewLife(){
    return newLife;
}
int Item::getNewDamage(){
    return newDamage;
}
//setters
void Item::setItemName(string tempItemName){
    itemName=tempItemName;
}
void Item::setNewHealth(int tempNewHealth){
    newHealth=tempNewHealth;
}
void Item::setNewLife(int tempNewLife){
    newLife=tempNewLife;
}
void Item::setNewDamage(int tempNewDamage){
    newDamage=tempNewDamage;
}
//constructors
Item::Item(string tempItemName, int tempNewHealth, int tempNewLife, int tempNewDamage){
    itemName=tempItemName;
    newHealth=tempNewHealth;
    newLife=tempNewLife;
    newDamage=tempNewDamage;
}
Item::Item(){
    
}
