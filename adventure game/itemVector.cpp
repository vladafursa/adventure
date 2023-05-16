#include "itemVector.hpp"
void itemVector::setItem(Item i1){
    item.push_back((i1));
}
Item* itemVector::getVectorItem(){
    return item.data();
}
int itemVector::getItemSize(){
    return item.size();
}
//for checking
void itemVector::displayItemVector(){
    Item* s= getVectorItem();
    for(int i=0;i<getItemSize();i++){
        cout<<"Name: "<<s->getItemName()<<endl;
        if(s->getNewHealth()!=0){
            cout<<"health points gained: "<<s->getNewHealth()<<endl;
        }
        else if(s->getNewLife()!=0){
            cout<<"lives gained: "<<s->getNewLife()<<endl;
        }
        else if(s->getNewDamage()!=0){
            cout<<"Damage gained: "<<s->getNewDamage()<<endl;
        }
        else{
            cout<<"This item doesn't increase any value"<<endl;
        }
        s++;
    }
}

void itemVector::readItemFile(string path){
    vector<Item> it1;
    string tempLine;
    string tempWord;
    string parseName;
    int parseHealth = 0;
    int parseLife= 0;
    int parseDamage = 0;
    ifstream fs;
    fs.open(path);
    try{
        if(!fs.is_open()){
            throw runtime_error("File cannot be opened");
        }
            while(getline(fs, tempLine)){
                stringstream ss(tempLine);
                int counter=0;
                while(getline(ss>>ws, tempWord, '#')){
                    if(counter==0){
                        parseName=tempWord;
                    }
                    if(counter==1){
                        parseHealth=stoi(tempWord);
                    }
                    if(counter==2){
                        parseLife=stoi(tempWord);
                    }
                    if(counter==3){
                        parseDamage=stoi(tempWord);
                    }
                    counter++;
                }
                Item* item=new Item(parseName, parseHealth, parseLife, parseDamage);
                setItem(*item);
            }
            fs.close();}
    catch (invalid_argument& e) {
                cerr << "exception has been thrown: " << e.what() << endl;
        exit(1);
    }
    catch(runtime_error& e){
        cerr<<"exception was thrown: "<<e.what()<<endl;
        if(path=="inventory.txt"){
            ofstream newFile;
            newFile.open("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/inventory.txt");
            //newFile.open("inventory.txt");
            cout<<"new file was created!"<<endl;
            newFile.close();
        }
        else{
            exit(1);}
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

void itemVector::writeInventory(Item* item){
    ofstream writeFile;
        writeFile.open("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/inventory.txt", std::ios::app);
    //writeFile.open("inventory.txt", std::ios::app);
    try{
        if(!writeFile.is_open()){
            throw runtime_error("File cannot be opened");
        }
        writeFile<<item->getItemName()<<"#"<<item->getNewHealth()<<"#"<<item->getNewLife()<<"#"<<item->getNewDamage()<<endl;
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


Item* itemVector::findItemRecord(string it){
    bool found = false;
    string parseName;
    int parseHealth;
    int parseLife;
    int parseDamage;
    Item* neededItem = new Item(); // Allocate memory for neededItem
    Item* search=getVectorItem();
    do{
        for(auto i=item.begin();i<item.end();i++){
            if(search->getItemName()==it){
                parseName=search->getItemName();
                parseHealth=search->getNewHealth();
                parseLife=search->getNewLife();
                parseDamage=search->getNewDamage();
                neededItem->setItemName(parseName);
                neededItem->setNewHealth(parseHealth);
                neededItem->setNewLife(parseLife);
                neededItem->setNewDamage(parseDamage);
                found=true;
            }
                search++;
        }
        if(found==false){
            cout<<"branch is not in the vector"<<endl;
        }
    }while(search->getItemName()!="");
    return neededItem;
}
