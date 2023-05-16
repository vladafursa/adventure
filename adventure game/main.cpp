#include <iostream>
#include "Gameplay.hpp"
#include "character.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include"Scenario.hpp"
#include "ScenarioVector.hpp"
#include "item.hpp"
#include "itemVector.hpp"
#include "enemyVector.hpp"
#include <ctime>
#include <stdlib.h>
using namespace std;
int main(int argc, const char * argv[]) {
    srand(time(NULL));
     Gameplay Game1;
     Game1.Menu(Game1.displayMenu());
    return 0;
}
