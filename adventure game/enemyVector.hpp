#ifndef enemyVector_hpp
#define enemyVector_hpp

#include <stdio.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include "enemy.hpp"
using namespace std;
class enemyVector{
private:
    vector<Enemy> enemy;
public:
    void setEnemy(Enemy e1);
    Enemy* getVectorEnemy();
    int getEnemySize();
    void displayEnemyVector();
    void readEnemyFile();
    Enemy* findEnemyRecord(string en);
};
#endif /* enemyVector_hpp */
