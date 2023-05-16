#include "ScenarioVector.hpp"
#include "Gameplay.hpp"
#include "enemyVector.hpp"
//Save pointer to object of class
StoryVector::StoryVector(Gameplay* Game1_ptr){
    Game1=Game1_ptr;
}
//destructor
StoryVector::~StoryVector(){
    
}

void StoryVector::setVectorItem(Story s1){
    story.push_back((s1));
}

Story* StoryVector::getVector(){
    return story.data();
}
int StoryVector::getSize(){
    return story.size();
}
//for checking scenario while making it
void StoryVector::displayStoryVector(){
    Story* s= getVector();
    for(int i=0;i<getSize();i++){
        cout<<"Current: "<<s->getCurrent()<<endl;
        cout<<"Description: "<<s->getDescription()<<endl;
        cout<<"Question: "<<s->getQuestion()<<endl;
        cout<<"Branch1: "<<s->getBranch1()<<endl;
        cout<<"Branch2: "<<s->getBranch2()<<endl;
        cout<<"Added lives:"<<s->getAddedLives()<<endl;
        cout<<"Added health:"<<s->getAddedHealth()<<endl;
        cout<<"Added damage:"<<s->getAddedDamage()<<endl;
        cout<<"Added score:"<<s->getAddedScore()<<endl;
        cout<<"Item: "<<s->getItem()<<endl;
        cout<<"Enemy: "<<s->getEnemy()<<endl;
        s++;
    }
}
void StoryVector::readFile(){
    vector<Story> vs1;
    string tempLine;
    string tempWord;
    string parseCurrent;
    string parseDescription;
    string parseQuestion;
    string parseBranch1;
    string parseBranch2;
    string parseItem;
    string parseEnemy;
    int parseAddedLives=0;
    int parseAddedHealth=0;
    int parseAddedDamage=0;
    int parseAddedScore=0;
    ifstream fs;
    fs.open("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/scenario.txt");
    //fs.open("scenario.txt");
    try{
        if(!fs.is_open()){
            throw runtime_error("File scenario.txt cannot be opened");
        }
            while(getline(fs, tempLine)){
                stringstream ss(tempLine);
                int counter=0;
                while(getline(ss>>ws, tempWord, '#')){
                    if(counter==0){
                        parseCurrent=tempWord;
                    }
                    if(counter==1){
                        parseDescription=tempWord;
                    }
                    if(counter==2){
                        parseQuestion=tempWord;
                    }
                    if(counter==3){
                        parseBranch1=tempWord;
                    }
                    if(counter==4){
                        parseBranch2=tempWord;
                    }
                    if(counter==5){
                        parseAddedLives=stoi(tempWord);
                    }
                    if(counter==6){
                        parseAddedHealth=stoi(tempWord);
                    }
                    if(counter==7){
                        parseAddedDamage=stoi(tempWord);
                    }
                    if(counter==8){
                        parseAddedScore=stoi(tempWord);
                    }
                    if(counter==9){
                        parseItem=tempWord;
                    }
                    if(counter==10){
                        parseEnemy=tempWord;
                    }
                    counter++;
                }
                Story* s=new Story(parseCurrent, parseDescription, parseQuestion, parseBranch1, parseBranch2, parseAddedLives, parseAddedHealth, parseAddedDamage, parseAddedScore, parseItem, parseEnemy);
                setVectorItem(*s);
            }
            fs.close();}
    //exception handling
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
/*accessed and modified fromhttps://stackoverflow.com/questions/21082171/optimal-way-to-delete-last-line-of-file-in-c*/
void StoryVector::deleteLastLine(){
    string line;
    vector<string> lines;
    ifstream inputStream("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/currentScenario.txt");
    //ifstream inputStream("currentScenario.txt");
    try{
        if(!inputStream.is_open()){
        throw runtime_error("File currentScenario.txt cannot be opened");
        }
        while (getline(inputStream,line)) {
            lines.push_back(line);
        }
        inputStream.close();
    }
    catch(runtime_error& e){
        cerr<<"exception was thrown: "<<e.what()<<endl;
       }
       catch(ifstream::failure e){
        cout<<"exception has been thrown"<<e.what()<<endl;
       }
       catch(exception e){
        cout<<"exception has been thrown:"<<e.what();
       }
    fstream outputStream("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/currentScenario.txt", ios::out | ios::trunc);
    //fstream outputStream("currentScenario.txt", ios::out | ios::trunc);
    try{
        if (!outputStream.is_open()){
        throw runtime_error("File currentScenario.txt cannot be opened");
        }
        for (int i=0; i < lines.size()-1; i++)
        {
            outputStream << lines[i] << "\n";
        }
        outputStream.close();
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
string StoryVector::findCurrent(){
    string current;
    string tempLine;
    string tempWord;
    ifstream fs;
    fs.open("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/currentScenario.txt");
    //fs.open("currentScenario.txt");
    try{
        if(!fs.is_open()){
            throw runtime_error("File current.txt cannot be opened");
        }
            while(getline(fs, tempLine)){
                stringstream ss(tempLine);
                int counter=0;
                while(getline(ss>>ws, tempWord, '#')){
                    if(counter==0){
                        current=tempWord;
                    }
                    counter++;
                }
            }
            fs.close();}
        
catch(runtime_error& e){
    cerr<<"exception was thrown: "<<e.what()<<endl;
    cout<<"New file was created"<<endl;
    ofstream newFile;
    newFile.open("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/currentScenario.txt");
    //newFile.open("/currentScenario.txt");
    newFile.close();
    findCurrent();
}
catch(ifstream::failure e){
    cout<<"exception has been thrown"<<e.what()<<endl;
}
catch(exception e){
    cout<<"exception has been thrown:"<<e.what();
}
    if(current!=""){deleteLastLine();}
    else{current="branch0";}
    return current;
}
//for future usage
string StoryVector::loadFullDescription(){
    string fullDescription="";
    string tempLine;
    string tempWord;
    fstream fs;
    fs.open("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/currentScenario.txt");
    //fs.open("currentScenario.txt");
    if(fs.is_open()){
        while(getline(fs, tempLine)){
            stringstream ss(tempLine);
            int counter=0;
            while(getline(ss>>ws, tempWord, '#')){
                if(counter==1){
                    fullDescription+=tempWord;
                }
                counter++;
            }
        }
        fs.close();}
        else{
            cout<<"file cannot be opened"<<endl;
    }
    return fullDescription;
}

//writing current scenario to a file
void StoryVector::writeToFile(Story* pointer){
    ofstream writeFile;
    writeFile.open("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/currentScenario.txt", std::ios::app);
    //writeFile.open("currentScenario.txt", std::ios::app);
    try{
     if(!writeFile.is_open()){
         throw runtime_error("File cannot be opened");
     }
    writeFile<<pointer->getCurrent()<<"#"<<pointer->getDescription()<<endl;
    pointer++;
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

//deleting data from a file
void StoryVector::clear(string filename)
{
   ofstream file(filename);
   // ofstream file("currentScenario.txt");
    try{
        if(!file.is_open()){
            throw runtime_error("File cannot be opened");
        }
        file<<"";
        file.close();
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

Story* StoryVector::findRecord(){
    bool found = false;
    int choiceStory;
    player.setDataFromFile();//if there are values in a file from a last game, they will be used
    item.readItemFile("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/item.txt");
    //item.readItemFile("item.txt");
    enemy.readEnemyFile();
    string branching=findCurrent();
    //string fullDescription;
    // if (branching!="branch0"){fullDescription=loadFullDescription();}
    Story* sRecord=getVector();
    do{
        for(auto i=story.begin();i<story.end();i++){
            if(sRecord->getCurrent()==branching){
                //  fullDescription+=sRecord->getDescription();
                writeToFile(sRecord);
                player.writeStats(player.getLives(), player.getHealth(), player.getDamage(), player.getScore());
                //if the eemy exists in this branch, combat mode
                if(sRecord->getEnemy()!=""){
                    cout<<"-----combat mode-----"<<endl;
                    Enemy* enemy1=enemy.findEnemyRecord(sRecord->getEnemy());
                    cout<<"Your opponent is: "<<endl;
                    enemy1->display();
                    cout<<"----------------------"<<endl;
                    player.combat(enemy1);
                    cout<<"Your current stats are: "<<endl;
                    player.display();
                }
                //if there is a collection of item in this branch, collect
                if(sRecord->getItem()!=""){
                    cout<<"-------items found-------"<<endl;
                    player.collectItem(item.findItemRecord(sRecord->getItem()));
                    player.displayCollectedItem(item.findItemRecord(sRecord->getItem()));
                    cout<<"----------------------"<<endl;
                }
                //if stats are changed in this branch
                player.changeStats(sRecord->getAddedLives(), sRecord->getAddedHealth(), sRecord->getAddedDamage(), sRecord->getAddedScore());
                cout<<"current stats: "<<endl;
                player.display();
                cout<<sRecord->getDescription();
                cout<<sRecord->getQuestion()<<endl;
                found=true;
                //branching to the next branch
                if(player.getLives()>=0){
                if(sRecord->getBranch1()!="" && sRecord->getBranch2()!=""){
                    cout<<"1 - "<<sRecord->getBranch1()<<endl;
                    cout<<"2 - "<<sRecord->getBranch2()<<endl;
                    cout<<"3 - display inventory"<<endl;
                    cout<<"4 - exit"<<endl;
                    bool loop=true;
                    while(loop==true){
                        choiceStory=Game1->getNumber();
                        if (choiceStory>0 and choiceStory<=4){
                            loop=false;
                        }
                        else{
                            cout<<"type in a valid choice"<<endl;
                        }
                    }
                    switch(choiceStory){
                        case(1):
                            if(sRecord->getItem()!=""){
                                //writing item to inventory to avoid duplication
                                item.writeInventory(item.findItemRecord(sRecord->getItem()));}
                            branching=sRecord->getBranch1();
                            break;
                        case(2):
                            if(sRecord->getItem()!=""){
                                //writing item to inventory to avoid duplication
                                item.writeInventory(item.findItemRecord(sRecord->getItem()));}
                            branching=sRecord->getBranch2();
                            break;
                        case(3):{
                            itemVector inventory;
                            inventory.readItemFile("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/inventory.txt");
                            //inventory.readItemFile("inventory.txt");
                            inventory.displayItemVector();
                            break;}
                        case(4):
                            Game1->Menu(Game1->displayMenu());
                            return 0;
                    }
                    
                }}
                break;
            }
            sRecord++;
        }
        if(found==false){
            cout<<"branch is not in the vector"<<endl;
        }
        
    }while(sRecord->getCurrent()!="" &&(sRecord->getBranch1()!="" && sRecord->getBranch2()!="")&&player.getLives()>=0);// while player is alive and the story is not finished
    if (player.getLives()<0){
        cout<<"you dead"<<endl;
    }
    else{
    player.additionalFinal();
    }
    cout<<"the game has finished"<<endl;
    //cleaning data from files for a new story
    clear("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/currentScenario.txt");
    clear("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/currentStats.txt");
    clear("/Users/vladafursa/Desktop/NTIC C++/adventure game/adventure game/inventory.txt");
   // clear("currentScenario.txt");
    //clear("currentStats.txt");
   // clear("inventory.txt");
    Game1->Menu(Game1->displayMenu());
    return sRecord;
}
