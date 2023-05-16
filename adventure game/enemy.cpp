#include "enemy.hpp"
//getter for name
string Enemy::getName(){
    return name;
}
//setter for name
void Enemy::setName(string tempName){
    name=tempName;
}
//destructor
Enemy::~Enemy(){
    
}
//constructors
Enemy::Enemy(){
    
}
Enemy::Enemy(string tempName, int tempLives, int tempHealth, int tempDamage){
    lives=tempLives;
    health=tempHealth;
    damage=tempDamage;
    name=tempName;
}
//display stats of enemy
void Enemy::display(){
    cout<<"Name: "<<getName()<<endl;
    Character::display();
}
