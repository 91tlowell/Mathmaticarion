#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"

using namespace std;

string letterCaseToUpper (string s){
    for (int i = 0; i < s.length(); i++){
        if ((s[i] >= 'a') && (s[i] <= 'z')){
            s[i] = (s[i] - 32);
        }
    }
    return s;
}

Map :: Map(){
    position_X = 0;
    position_Y = 0;
}

void Map :: setPositionX(int posX){
    position_X = posX;
} // function works

void Map :: setPositionY(int posY){
    position_Y = posY;
} // function works

int Map :: get_XPosition(){
    return position_X;
} // function works

int Map :: get_YPosition(){
    return position_Y;
} // function works

string Map :: travelTaskGeneratorFunction(int idx){
    int randomIdx = 0;
    randomIdx = idx;
    string task = "";
    task = taskToTravelArray[randomIdx];
    return task;
}  // member function works

void Map :: loadMapToArray(string fileName){
    ifstream in_file;
    in_file.open(fileName);
    string line;
    int j = 0;
    int i = 0;
    string temp = "";
    if (in_file.fail()){
        cout << "Failed to open file: " << fileName << endl;
    }
    while (getline(in_file, line)){
        line = line + ',';
        for (int k = 0; k < line.length(); k++){
            if (line[k] != ','){      // condition to add all characters but delimiter to temporary string
                temp = temp + line[k];
            }
            else{
                if(!temp.empty()){      // condition to make sure delimiter does not go into the assingment array.
                    mapArr[i][j] = temp;
                    j++;
                    temp = "";
                }
            }
        }
        i++;
        j = 0;
    }
    // for (int i = 0; i < 15; i++){
    //     for (int j = 0; j < 15; j++){
    //         cout << mapArr[i][j];
    //     }
    //     cout << endl;
    // }
}    // member function works

void Map :: printMap(string fileName){
    ifstream in_file;
    in_file.open(fileName);
    string line;
    int i = 0;
    if (in_file.fail()){
        cout << "Failed to open file: " << fileName << endl;
    }
    while (getline(in_file, line)){
        cout << line << endl;
    }
}  // member function works

string Map :: getMapLocation(){
    string mapLocation = "";
    mapLocation = mapArr[get_XPosition()][get_YPosition()];
    cout << "this is x pos " << get_XPosition() << "this is Y pos " << get_YPosition() << endl;
    return mapLocation;
} // member function works

string Map :: checkPlayerPostition(){
    string mapLocation = mapArr[get_XPosition()][get_YPosition()];
    
    if (mapLocation == "S"){
        return "You may begin your journey!";
    }
    else if (mapLocation == "U"){
        return "Welcome to the Shop! How may I be of service?";
    }
    else if (mapLocation == "B"){
        return "Welcome to, the Thunder Dome!";
    }
    else if (mapLocation == "~"){
        return "These waters are dangerous, best to keep to dry land.";
    }
    else if (mapLocation == "^"){
        return "These mountains are treacherous, best to keep to flat land.";
    }
    else if (mapLocation == "_"){
        return "Solve the task to proceed.";
    }
} // member function works

void Map :: travelFunction(string userInput){
        // string userInput = "";
        // cout << "To move your character, enter either 'N' (north), 'S' (south), 'E' (east), or 'W' (west). " << endl;
        // letterCaseToUpper(userInput); // this will be part of the menu loop?
        if (letterCaseToUpper(userInput) == "N"){
            if ((get_XPosition() - 1) >= 0){
                setPositionX(get_XPosition() - 1);
                cout << getMapLocation() << endl;
                cout << checkPlayerPostition() << endl;
            }
            else{
                cout << "Out of bounds, can't go North anymore." << endl;
            }

        }
        else if (letterCaseToUpper(userInput) == "S"){
            if ((get_XPosition() + 1) < 15){
                setPositionX(get_XPosition() + 1);
                cout << getMapLocation() << endl;
                cout << checkPlayerPostition() << endl;
            }
            else{
                cout << "Out of bounds, can't go South anymore." << endl;
            }
        }
        else if (letterCaseToUpper(userInput) == "E"){
            if ((get_YPosition() + 1) < 14){
                cout << "this is X pos " << get_XPosition() << endl;
                setPositionY(get_YPosition() + 1);
                cout << getMapLocation() << endl;
                cout << checkPlayerPostition() << endl;
            }
            else{
                cout << "Out of bounds, can't go East anymore." << endl;
            }
        }
        else if (letterCaseToUpper(userInput) == "W"){
            if (get_YPosition() - 1 >= 0){
                setPositionY(get_YPosition() - 1);
                cout << getMapLocation() << endl;
                cout << checkPlayerPostition() << endl;
            }
            else{
                cout << "Out of bounds, can't go West anymore." << endl;
            }
        }
}   // member function works    account for edge cases "edge of maps"

void Map :: loadTaskToTravelArray(string fileName){
    ifstream in_file;
    in_file.open(fileName);
    string line;
    int j = 0;
    int i = 0;
    string temp = "";
    if (in_file.fail()){
        cout << "Failed to open file: " << fileName << endl;
    }
    while (getline(in_file, line)){
        line = line + ',';
        for (int k = 0; k < line.length(); k++){
            if (line[k] != ','){      // condition to add all characters but delimiter to temporary string
                temp = temp + line[k];
            }
            else{
                if(!temp.empty()){      // condition to make sure delimiter does not go into the assingment array.
                    taskToTravelArray[i] = temp;
                    i++;
                    temp = "";
                }
            }
        }
        // i++;
        // j = 0;
    }
    // for (int i = 0; i < taskToTravelSIZE; i++){
    //     cout << taskToTravelArray[i];
    // }
}    // member function works

void Map :: loadTaskToTravelArrayAnswers(string fileName){
    ifstream in_file;
    in_file.open(fileName);
    string line;
    int j = 0;
    int i = 0;
    string temp = "";
    if (in_file.fail()){
        cout << "Failed to open file: " << fileName << endl;
    }
    while (getline(in_file, line)){
        line = line + ',';
        for (int k = 0; k < line.length(); k++){
            if (line[k] != ','){      // condition to add all characters but delimiter to temporary string
                temp = temp + line[k];
            }
            else{
                if(!temp.empty()){      // condition to make sure delimiter does not go into the assingment array.
                    taskToTravelArrayAnswers[i] = temp;
                    i++;
                    temp = "";
                }
            }
        }
        // i++;
        // j = 0;
    }
    // for (int i = 0; i < taskToTravelSIZE; i++){
    //     cout << taskToTravelArrayAnswers[i];
    // }
}    // member function works

int Map :: randomNumGeneratorForTravelTask(){
    int randomIdx = 0;
    randomIdx = rand()%(270);
    return randomIdx;
}

string Map :: travelFunctionAnswerCheck(int idx){
    string temp = "";
    temp = taskToTravelArrayAnswers[idx];
    return temp;
}