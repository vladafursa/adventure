#include<iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "player.hpp"
//getter for score
int Player:: getScore(){
    return score;
}
//setter for score
void Player::setScore(int tempScore){
    score=tempScore;
}
//destructor
Player::~Player(){
    
}
//constructors
Player::Player(){

}

Player::Player(int tempLives, int tempHealth, int tempDamage, int tempScore){
    lives=tempLives;
    health=tempHealth;
    damage=tempDamage;
    score=tempScore;
}
//display of the whole attributes using parent function
void Player::display(){
    Character::display();
    cout<<"current score: "<<getScore()<<endl;
}
//collecting items with converting
void Player:: collectItem(Item* item){
    inventory.push_back(*item);
    health+=item->getNewHealth();
    lives+=item->getNewLife();
    damage+=item->getNewDamage();
    convert();
}
Item* Player::getInventoryVector(){
    return inventory.data();
}
void Player::displayCollectedItem(Item* item){
    
        cout<<"Name: "<<item->getItemName()<<endl;
        if(item->getNewHealth()!=0){
            cout<<"healths gained: "<<item->getNewHealth()<<endl;
        }
        else if(item->getNewLife()!=0){
            cout<<"lives gained: "<<item->getNewLife()<<endl;
            
        }
        else if(item->getNewDamage()!=0){
            cout<<"Damage gained: "<<item->getNewDamage()<<endl;
            
        }
        else{
            cout<<"This item doesn't increase any value"<<endl;
        }
        item++;
    }


void Player::setDataFromFile(){
    string tempWord;
    int parseHealth;
    int parseLife;
    int parseDamage;
    int parseScore;
    fstream fs;
    try{
        fs.open("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/currentStats.txt");
        // fs.open("currentStats.txt");
        if(!fs.is_open()){
            throw runtime_error("File cannot be opened");
        }
        if(fs.peek() != EOF){
            int counter=0;
            while(getline(fs, tempWord, '#')){
                if(counter==0){
                    parseLife=stoi(tempWord);}
                if(counter==1){
                    parseHealth=stoi(tempWord);
                }
                if(counter==2){
                    parseDamage=stoi(tempWord);
                }
                if(counter==3){
                    parseScore=stoi(tempWord);
                }
                counter++;
            }
            setLives(parseLife);
            setHealth(parseHealth);
            setDamage(parseDamage);
            setScore(parseScore);
            }
        fs.close();
        
    }
    catch (invalid_argument& e) {
                cerr << "exception has been thrown: " << e.what() << endl;
        exit(1);
    }
    catch(runtime_error& e){
        cerr<<"exception was thrown: "<<e.what()<<endl;
        cout<<"New file was created"<<endl;
        ofstream newFile;
        newFile.open("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/currentStats.txt");
        //newFile.open("currentStats.txt");
        newFile.close();
        setDataFromFile();
    }
    catch(ifstream::failure e){
        cout<<"exception has been thrown"<<e.what()<<endl;
    }
    catch(exception e){
        cout<<"exception has been thrown:"<<e.what();
    }
}

void Player::writeStats(int parselives, int parseHealth, int parseDamage, int parseScore){
    ofstream writeFile;
    writeFile.open("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/currentStats.txt");
    //writeFile.open("currentStats.txt");
    try{
        if(!writeFile.is_open()){
            throw runtime_error("File cannot be opened");
        }
        writeFile<<parselives<<"#"<<parseHealth<<"#"<<parseDamage<<"#"<<parseScore;
        writeFile.close();
    }
    catch(runtime_error& e){
        cerr<<"exception was thrown: "<<e.what()<<endl;
    }
    catch(ofstream::failure e){
        cout<<"exception has been thrown"<<e.what()<<endl;
    }
    catch(exception e){
        cout<<"exception has been thrown:"<<e.what();
    }
}
void Player::combat(Enemy* enemy){
    int player_Damage=getDamage()+(rand() % 100);
    int enemy_Damage=enemy->getDamage()+(rand() % 100);
    while((enemy->getLives()>-1)&&(getLives()>-1)){
        cout<<"player damage: "<<player_Damage<<endl;
        cout<<"enemy damage: "<<enemy_Damage<<endl;
        //this_thread::sleep_for(std::chrono::seconds(2));
        cout<<"--------------"<<endl;
        cout<<"Player status:"<<endl;
        setHealth(getHealth()-enemy_Damage);
        convert();
        cout<<"lives: "<<getLives()<<endl;
        cout<<"health: "<<getHealth()<<endl;
        //this_thread::sleep_for(std::chrono::seconds(3));
        cout<<"--------------"<<endl;
        cout<<"Enemy status:"<<endl;
        enemy->setHealth(enemy->getHealth()-player_Damage);
        enemy->convert();
        cout<<"lives: "<<enemy->getLives()<<endl;
        cout<<"health: "<<enemy->getHealth()<<endl;
        //this_thread::sleep_for(std::chrono::seconds(3));
        cout<<"--------------"<<endl;
        if(enemy->getLives()<0 &&getLives()>=0){
            cout<<"You won and gained 20 score"<<endl;
            setScore(getScore()+20);
        }
        else if(enemy->getLives()<0 &&getLives()<0){
            if(getHealth()>enemy->getHealth())
                {cout<<"You won and gained 20 score!"<<endl;
                setScore(getScore()+20);}
            else{
                cout<<"you loose"<<endl;
            }
        }
        combat(enemy);
    }
    
}
void Player::changeStats(int addLives, int addHealth, int addDamage, int addScore){
    lives+=addLives;
    health+=addHealth;
    damage+=addDamage;
    score+=addScore;
    convert();
    if (addLives!=0){
        cout<<"You have gained "<<addLives<<" lives"<<endl;
    }
    if (addHealth!=0){
        cout<<"You have gained "<<addHealth<<" health"<<endl;
    }
    if (addDamage!=0){
        cout<<"You have gained "<<addDamage<<" damage"<<endl;
    }
    if (addScore!=0){
        cout<<"You have gained "<<addScore<<" score"<<endl;
    }
}
void Player::additionalFinal(){
    if (score<=30){
        cout<<"You can't fight and help others"<<endl;
    }
    if (score>30&&score<60){
        cout<<"You cant fight, but not help others"<<endl;
    }
    if (score>=60){
        cout<<"You are a very nice person, be proud of yourself!"<<endl;
    }
}
