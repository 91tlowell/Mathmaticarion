#include <iostream>
#include <string>
#include <fstream>
#include "Boss.h"

using namespace std;

Boss :: Boss(){
    index = 0;
    bossHealth = 100;
}

int Boss :: getBossHealth(){
    return bossHealth;
}    // member function works

int Boss :: getBossStamina(){
    return bossStamina;
}   // member function works

void Boss :: setBossHealth(int bossHealth_){
    bossHealth = bossHealth_;
}    // member function works

void Boss :: printTaskList(){
    for (int i = 0; i < size - 1; i++){
        cout << bossArray[i] << endl;
    }
}   // member function works

void Boss :: loadTaskToArray(string fileName){
    ifstream in_file;
    in_file.open(fileName);
    string line;
    int j = 0;
    string temp = "";
    if (in_file.fail()){
        cout << "Failed to open file: " << fileName << endl;
    }
    while (getline(in_file, line)){
        line = line + ',';
        for (int i = 0; i < line.length(); i++){
            if (line[i] != ','){      // condition to add all characters but delimiter to temporary string
                temp = temp + line[i];
            }
            else{
                // cout << temp<<endl;  // check if temp is obtaining proper characters
                if(!temp.empty()){      // condition to make sure delimiter does not go into the assingment array.
                    bossArray[j++] = temp;
                    temp = "";
                }
            }
        }
    }
    // for (int i = 0; i < 40; i++){
    //     cout << bossArray[i] << endl;
    // }
} // member function works depending on the players XP value, a specific task list will be loaded.

void Boss :: loadTaskAnswToArray(string fileName){
    ifstream in_file;
    in_file.open(fileName);
    string line;
    int j = 0;
    string temp = "";
    if (in_file.fail()){
        cout << "Failed to open file: " << fileName << endl;
    }
    while (getline(in_file, line)){
        line = line + ',';
        for (int i = 0; i < line.length(); i++){
            if (line[i] != ','){      // condition to add all characters but delimiter to temporary string
                temp = temp + line[i];
            }
            else{
                // cout << temp<<endl;  // check if temp is obtaining proper characters
                if(!temp.empty()){      // condition to make sure delimiter does not go into the assingment array.
                    bossAnswArray[j++] = temp;
                    temp = "";
                }
            }
        }
    }
    // for (int i = 0; i < 40; i++){
    //     cout << bossAnswArray[i] << endl;
    // }
} // member function works depending on the players XP value, a specific task list will be loaded.
    
string Boss :: presentTaskFunction(int idx){
    int randomIdx = 0;
    randomIdx = idx;
    string task = "";
    task = bossArray[randomIdx];
    return task;
}  // member function works choose random index to display task while fighting boss.

string Boss :: presentTaskFunctionAnswer(int idx){
    int randomIdx = 0;
    randomIdx = idx;
    string answer = "";
    answer = bossAnswArray[randomIdx];
    return answer;
}  // member functions works

string Boss :: responseFunction(string answer){
    
} // if the player gets task correct or incorrect a response is displayed at random.

int Boss :: getIndexTaskList(){
    return index;
} // member function works

void Boss :: setIndexTaskList(int index_){
    index = index_;
}  // member function works
    
// void Boss :: checkAnswerFunction(){
    
// }

int Boss :: randomNumGenerator(){
    int randomIdx = 0;
    randomIdx = rand()%(40);
    return randomIdx;
}   // member function works