#include <iostream>
#include "character.hpp"
//getter for lives
int Character:: getLives(){
    return lives;
}
//setter for lives
void Character::setLives(int tempLives){
    lives=tempLives;
}
//getter for health
int Character::getHealth(){
    return health;
}
//setter for health
void Character::setHealth(int tempHealth){
    health=tempHealth;
}
//getter for damage
int Character::getDamage(){
    return damage;
}
//setter for damage
void Character::setDamage(int tempDamage){
    damage=tempDamage;
}
//default constructor
Character::Character(){
    health=100;
    lives=1;
    damage=0;
}
//converting lives into health and vise verca
void Character::convert(){
    if (health>100){
        lives++;
        health=health-100;
    }
    if(health<=0){
        lives--;
        health=health+100;
    }
}
//constructor
Character::Character(int tempLives, int tempHealth, int tempdamage){
    lives=tempLives;
    health=tempHealth;
    damage=tempdamage;
}
//display of all attributes
void Character::display(){
    cout<<"number of lives: "<<getLives()<<endl;
    cout<<"health status: "<<getHealth()<<endl;
    cout<<"damage: "<<getDamage()<<endl;
}
