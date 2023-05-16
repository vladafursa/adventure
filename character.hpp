#ifndef character_hpp
#define character_hpp
using namespace std;
#include <stdio.h>
class Character{
protected:
    int lives;
    int health;
    int damage;
public:
    Character();//default constructor
    Character(int tempLives, int tempHealth, int tempdamage);
    int getLives();
    void setLives(int tempLives);
    int getHealth();
    void setHealth(int tempHealth);
    int getDamage();
    void setDamage(int tempDamage);
    void convert();//convert lives into health and vise verca
    void display();
};
#endif /* character_hpp */
