#include <cstdlib>
#include "enemyVector.hpp"
void enemyVector::setEnemy(Enemy e1){
    enemy.push_back((e1));
}
Enemy* enemyVector::getVectorEnemy(){
    return enemy.data();
}
int enemyVector::getEnemySize(){
    return enemy.size();
}
void enemyVector::displayEnemyVector(){
    Enemy* e= getVectorEnemy();
    for(int i=0;i<getEnemySize();i++){
        cout<<"Name: "<<e->getName()<<endl;
        cout<<"Life: "<<e->getLives()<<endl;
        cout<<"Health: "<<e->getHealth()<<endl;
        cout<<"Damage: "<<e->getDamage()<<endl;
        e++;
    }
}
void enemyVector::readEnemyFile(){
    vector<Enemy> en1;
    string tempLine;
    string tempWord;
    string parseName;
    int parseHealth = 0;
    int parseLife= 0;
    int parseDamage = 0;
    fstream fs;
    fs.open("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/enemy.txt");
    //fs.open("enemy.txt");
    try{
        if(!fs.is_open()){
            throw runtime_error("File enemy.txt cannot be opened");
        }
        else{
            while(getline(fs, tempLine)){
                stringstream ss(tempLine);
                int counter=0;
                while(getline(ss>>ws, tempWord, '#')){
                    if(counter==0){
                        parseName=tempWord;
                    }
                    if(counter==1){
                        parseLife=stoi(tempWord);
                    }
                    if(counter==2){
                        parseHealth=stoi(tempWord);
                    }
                    if(counter==3){
                        parseDamage=stoi(tempWord);
                    }
                    counter++;
                }
                Enemy* enemy=new Enemy(parseName, parseLife, parseHealth, parseDamage);
                setEnemy(*enemy);
            }
            fs.close();}
        
    }
    catch (invalid_argument& e) {
                cerr << "exception has been thrown: " << e.what() << endl;
        exit(1);
    }
    catch(runtime_error& e){
        cerr<<"exception was thrown: "<<e.what()<<endl;
        exit(1);
    }
    catch(ifstream::failure e){
        cout<<"exception has been thrown"<<e.what()<<endl;
        exit(1);
    }
    catch(exception e){
        cout<<"exception has been thrown:"<<e.what();
        exit(1);
    }
}
Enemy* enemyVector::findEnemyRecord(string en){
    bool found = false;
    string parseName;
    Enemy* neededEnemy = new Enemy(); // Allocate memory for neededItem
    Enemy* search=getVectorEnemy();
    do{
        for(auto i=enemy.begin();i<enemy.end();i++){
            if(search->getName()==en){
                neededEnemy->setName(search->getName());
                neededEnemy->setLives(search->getLives());
                neededEnemy->setHealth(search->getHealth());
                neededEnemy->setDamage(search->getDamage());
                found=true;
            }
                search++;
        }
        if(found==false){
            cout<<"branch is not in the vector"<<endl;
        }
    }while(search->getName()!="");
    return neededEnemy;
}

