#include "Scenario.hpp"
//getters
string Story::getCurrent(){
    return current;
}
string Story::getDescription(){
    return description;
}
string Story::getQuestion(){
    return question;
}
string Story::getBranch1(){
    return branch1;
}
string Story::getBranch2(){
    return branch2;
}
string Story::getItem(){
    return item;
}
string Story::getEnemy(){
    return enemy;
}
int Story::getAddedLives(){
    return addedLives;
}
int Story::getAddedHealth(){
    return addedHealth;
}
int Story::getAddedDamage(){
    return addedDamage;
}
int Story::getAddedScore(){
    return addedScore;
}
//setters
void Story::setCurrent(string tempCurrent){
    current=tempCurrent;
}
void Story::setDescription(string tempDescription){
    description=tempDescription;
}
void Story::setBranch1(string tempBranch1){
    branch1=tempBranch1;
}
void Story::setBranch2(string tempBranch2){
    branch2=tempBranch2;
}
void Story::setQuestion(string tempQuestion){
    question=tempQuestion;
}
void Story::setItem(string tempItem){
    item=tempItem;
}
void Story::setEnemy(string tempEnemy){
    item=tempEnemy;
}

void Story::setAddedLives(int tempAddedLives){
    addedLives=tempAddedLives;
}
void Story::setAddedHealth(int tempAddedHealth){
    addedHealth=tempAddedHealth;
}
void Story::setAddedDamage(int tempAddedDamage){
    addedDamage=tempAddedDamage;
}
void Story::setAddedScore(int tempAddedScore){
    addedScore=tempAddedScore;
}
//constructors
Story::Story(string tempCurrent, string tempDescription, string tempQuestion, string tempBranch1, string tempBranch2,int tempAddedLives, int tempAddedHealth, int tempAddedDamage, int tempAddedScore,string tempItem, string tempEnemy){
    current=tempCurrent;
    description=tempDescription;
    question=tempQuestion;
    branch1=tempBranch1;
    branch2=tempBranch2;
    addedLives=tempAddedLives;
    addedHealth=tempAddedHealth;
    addedDamage=tempAddedDamage;
    addedScore=tempAddedScore;
    item=tempItem;
    enemy=tempEnemy;
    
};
Story::Story(){
    
}
