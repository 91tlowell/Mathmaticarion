#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "Boss.h"
#include "Attribute.h"
#include "Map.h"
#include "Game.h"

using namespace std;

int split(string wordsInt, char delim, string inputArr[], int arrLength){   // return function int 4 parameters, string, char, array, int
    string temp="";
    int count = 0;  // count variable to keep track of number of words
    int arLen = 0;  // temp variable to keep track of delimiter
    if (wordsInt == ""){
        return 0;
    }
    else{
        wordsInt = wordsInt + delim;
        //cout << wordsInt; // check to see if addition of delimiter was correct.
        for (int i = 0; i < wordsInt.length(); i++){
            if (wordsInt[i] != delim){      // condition to add all characters but delimiter to temporary string
                temp = temp + wordsInt[i];
                
            }
            else{
                // cout << temp<<endl;  // check if temp is obtaining proper characters
                if(!temp.empty()){      // condition to make sure delimiter does not go into the assingment array.
                    inputArr[arLen++] = temp;
                    count++;
                    temp = "";
                }
            }
        }
        return count;
    }
}


Game :: Game(){
        
}

void Game :: menuLoop(){
    cout << endl;
    cout << "----------Welcome to Mathmaticarion----------" << endl;
    cout << endl;
    cout << "Please choose one of the following numerical options." << endl;
    int option = 0;
    while (option != 4){
        cout << "----------------Top Menu---------------------" << endl;
        cout << "1. What to expect in this game." << endl;
        cout << "2. Start Game." << endl;
        cout << "3. Load saved game." << endl;
        cout << "4. Quite Game." << endl;
        cin >> option;
        
        if (option == 1){
            ifstream in_file;
            in_file.open("Expectations.txt");
            string line;
            while (getline(in_file, line)){
                cout << line << endl;
            }
        }
        
        if (option == 2){
            map.loadMapToArray("map1ToArray.txt");
            map.loadTaskToTravelArray("taskToTravel.txt");
            map.loadTaskToTravelArrayAnswers("taskToTravelAnswers.txt");
            boss.loadTaskToArray("boss1TaskFile.txt");
            boss.loadTaskAnswToArray("boss1TaskAnswerFile.txt");
            int BossHealth = 0;
            BossHealth = boss.getBossHealth();
            
            while (BossHealth > 0){
                int idx = 0;
                int tempHealth = 0;
                int tempXP = 0;
                int option = 0;
                string answer = "";
                idx = map.randomNumGeneratorForTravelTask();
                string userInput = "";
                cout << "To move your character, enter either 'N' (north), 'S' (south), 'E' (east), or 'W' (west). " << endl;
                cin >> userInput;
                map.travelFunction(userInput);
                cout << map.travelTaskGeneratorFunction(idx) << endl;
                cin >> answer;
                cout << "****************" << endl;
                cout << "Player XP pre answer: " << player.getExperiencePoints() << endl;
                cout << "****************" << endl;
                if (answer == map.travelFunctionAnswerCheck(idx)){
                    tempXP = player.getExperiencePoints();
                    tempXP = tempXP + 1;
                    player.setExperiencePoints(tempXP);
                }
                cout << "Player XP post answer: " << player.getExperiencePoints() << endl;
                cout << "****************" << endl;
                cout << "Player Health pre answer: " << player.getHealth() << endl;
                cout << "****************" << endl;
                if (answer != map.travelFunctionAnswerCheck(idx)){
                    tempHealth = player.getHealth();
                    tempHealth = tempHealth - 1;
                    player.setHealth(tempHealth);
                }
                cout << "Player Health post answer: " << player. getHealth() << endl;
                if (map.getMapLocation == "U"){
                    storeFunction();
                }
                if (map.getMapLocation == "B"){
                    cout << "--------Boss Layer---------" << endl;
                    cout << "---Do you want to fight?---" << endl;
                    cout << "1. Yes" << endl;
                    cout << "2. No, come back another time"<< endl;
                    cin >> option;
                    if (option == 1){
                        fight();
                    }
                    else{
                        
                    }
                }

            }
        }
    }
    
    // map.loadMapToArray("map1ToArray.txt");
    // map.setPositionX(14);
    // map.setPositionY(13);
    // cout << "->" << map.getMapLocation()  << endl;
    // cout << "pre function call" << boss.getBossHealth() << endl;
    // checkAnswerFunction();
    // cout << "post function call" << boss.getBossHealth() << endl;
    // fight();
    // storeFunction(); 
    
}

void Game :: fight(){
    int option = 0;
    if (map.getMapLocation() == "B"){
        while(option != 2){
            cout << "Select a numeric option" << endl;
            cout << "-------Prepare for Battle--------" << endl;
            cout << "1. Fight" << endl;
            cout << "2. Run" << endl;
            cin >> option;
            if (option == 1){
                while (boss.getBossHealth() > 0){
                    checkAnswerFunction();
                }
            }
        }
    }
}

void Game :: checkAnswerFunction(){
    int XP = 0;
    XP = player.getExperiencePoints();
    string answer = "";
    int idx = 0;
    idx = boss.randomNumGenerator();
    cout << boss.presentTaskFunction(idx) << endl;
    cin >> answer;
    if (boss.presentTaskFunctionAnswer(idx) == answer){
        XP = XP + 1;
        player.setExperiencePoints(XP);
        int temp = 0;
        temp = boss.getBossHealth();
        boss.setBossHealth(temp - stoi(answer));
    }
} // member function works

void Game :: loadGameLevelFunction(string inFileName){
    ifstream in_file;
    in_file.open(inFileName);
    string line;
    string temp = "";
    string inputArr[7];
    if (in_file.fail()){
        cout << "File failed to open," << endl;
    }
    else{
        while (getline(in_file, line)){
            cout << line << endl;
            if (!line.empty()){
                split(line, ',', inputArr, 7);
                temp = inputArr[0];
                cout << temp << endl;
                attribute.setAddUgrade(temp);
                temp = "";
                temp = inputArr[1];
                cout << temp << endl;
                attribute.setAddUgrade(temp);
                temp = "";
                temp = inputArr[2];
                cout << temp << endl;
                player.setExperiencePoints(stoi(temp));
                temp = "";
                temp = inputArr[3];
                player.setHealth(stoi(temp));
                temp = "";
                temp = inputArr[4];
                player.setStamina(stoi(temp));
                temp = "";
                temp = inputArr[5];
                map.setPositionX(stoi(temp));
                temp = "";
                temp = inputArr[6];
                map.setPositionY(stoi(temp));
            }
        }
    }
    // player.setExperiencePoints(30);

    if (player.getExperiencePoints() < 25){
        map.loadTaskToTravelArray("taskToTravel.txt");
        map.loadMapToArray("map1ToArray.txt");
        map.printMap("level1Map.txt");
        boss.loadTaskToArray("boss1TaskFile.txt");
        boss.loadTaskAnswToArray("boss1TaskAnswerFile.txt");
    }
    else if (player.getExperiencePoints() > 25 && player.getExperiencePoints() < 50){
        map.loadTaskToTravelArray("taskToTravel.txt");
        map.loadMapToArray("map2ToArray.txt");
        map.printMap("level2Map.txt");
        boss.loadTaskToArray("boss2TaskFile.txt");
        boss.loadTaskAnswToArray("boss2TaskAnswerFile.txt");
    }
    else if (player.getExperiencePoints() > 50 && player.getExperiencePoints() < 75){
        map.loadTaskToTravelArray("taskToTravel.txt");
        map.loadMapToArray("map3ToArray.txt");
        map.printMap("level3Map.txt");
        boss.loadTaskToArray("boss3TaskFile.txt");
        boss.loadTaskAnswToArray("boss3TaskAnswerFile.txt");
    }
    else if (player.getExperiencePoints() > 75){
        map.loadTaskToTravelArray("taskToTravel.txt");
        map.loadMapToArray("map4ToArray.txt");
        map.printMap("level4Map.txt");
        boss.loadTaskToArray("boss4TaskFile.txt");
        boss.loadTaskAnswToArray("boss4TaskAnswerFile.txt");
    }
}   // member function works

void Game :: storeFunction(){
    if (map.getMapLocation() == "U"){
        int option = 0;
        map.checkPlayerPostition();
        while (option != 3){
            cout << "Select a numeric option" << endl;
            cout << "-------Percy's Upgrade Shop--------" << endl;
            cout << "1. Purchase Health" << endl;
            cout << "2. Purchase an Upgrade" << endl;
            cout << "3. Leave Shop" << endl;
            cin >> option;
            if (option == 1){
                int health = 0;
                int netMoney = 0;
                int moneySpent = 0;
                int newNetMoney = 0;
                cout << "Well Lets get you nursed back to good health!" << endl;
                health = player.getHealth();
                moneySpent = 100 - health;
                netMoney = player.getCurrency();
                newNetMoney = netMoney - moneySpent;
                player.setCurrency(newNetMoney);
            }
            else if (option == 2){
                int option_ = 0;
                cout << "Lets see if we can find something that suites your needs." << endl;
                cout << "Here is a list of upgrades: " << attribute.getListOfUpgrades() << endl;
                cout << "The upgrades are numbered 0 - 5. Choose a number and we'll getcha on your way." << endl;
                cin >> option_;
                if (option_ == 0){
                    attribute.setAddUgrade("Minimize Health Loss");
                }
                else if (option_ == 1){
                    attribute.setAddUgrade("Minimize Stamina Loss");
                }
                else if (option_ == 2){
                    attribute.setAddUgrade("Access Task List");
                }
                else if (option_ == 3){
                    attribute.setAddUgrade("Evade Upgrade");
                }
                else if (option_ == 4){
                    attribute.setAddUgrade("Access Map Upgrade");
                }
                else if (option_ == 5){
                    attribute.setAddUgrade("Jump To Map Location");
                }
            }
            else{
                cout << "Good luck on your journey! Hope to see you around" << endl;
            }
        }
    }
}   // member function works

void Game :: saveGameFunction(string outFileName){
    ofstream out_file;
    out_file.open(outFileName);
    if (out_file.fail()){
        cout << "Out file failed to open," << endl;
    }
    
    out_file << attribute.getPlayerUpgradeList() << player.getExperiencePoints() << "," << player.getHealth() << "," <<
    player.getStamina() << "," << map.get_XPosition() << "," << map.get_YPosition() << endl;
}  // member function works