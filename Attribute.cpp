#include <iostream>
#include <fstream>
#include <string>
#include "Attribute.h"

using namespace std;

Attribute :: Attribute(){
    
}

string Attribute :: getListOfUpgrades(){
    string upgradeList = "";
    for (int i = 0; i < SIZE_; i++){
        upgradeList = upgradeList + listOfUpgrades[i];
    }
    return upgradeList;
}    // member function works

void Attribute :: setAddUgrade(string addUpgrade){
    if (upgrades[0] == ""){
        upgrades[0] = addUpgrade;
    }
    else if (upgrades[1] == ""){
        upgrades[1] = addUpgrade;
    }
    else if ((upgrades[0] != "") && (upgrades[1] != "")){
        cout << "Your upgrades are full, you may not add anymore upgrades." << endl;
    }
}  // member function works

string Attribute :: getPlayerUpgradeList(){
    string upgradeList = "";
    upgradeList = upgrades[0] + ", " + upgrades[1];

    return upgradeList;
} // member function works

int Attribute :: healthUpgradeFunction(int damage){
    int health_ = 0;
    if (upgrades[0] == "Minimize Health Loss"){
        damage = damage / 2;
        health_ = player.getHealth() - damage;
        player.setHealth(health_);
    }
    else if (upgrades[1] == "Minimize Health Loss"){
        damage = damage / 2;
        health_ = player.getHealth() - damage;
        player.setHealth(health_);
    }
    else{
        return 0;
    }
    
    return health_;
} // member function works

int Attribute :: staminaUpgradeFunction(int stamina_){
    
}

void Attribute :: accessTaskListsUpgradeFucntion(){
    if (upgrades[0] == "Access Task Lists"){
        boss.printTaskList();
    }
    else if (upgrades[1] == "Access Task Lists"){
        boss.printTaskList();
    }
} // member function works

int Attribute :: evadeUpgradeFunction(int obtainedXP){
    int XP = obtainedXP;
    if (upgrades[0] == "Evade Upgrade"){
    }
    else if (upgrades[1] == "Evade Upgrade"){
    }
    else{
        return 0;
    }
    return XP;
}  // member function works

void Attribute :: jumpToMapLocation(int X, int Y){
    if (upgrades[0] == "Jump To Map Location"){
        map.setPositionX(X);
        map.setPositionY(Y);
        // map.getMapLocation();
        // map.checkPlayerPostition();
    }
    else if (upgrades[1] == "Jump To Map Location"){
        map.setPositionX(X);
        map.setPositionY(Y);
        // map.getMapLocation();
        // map.checkPlayerPostition();       
    }
}

int Attribute :: getX(){
    return map.get_XPosition(); 
}    // member functin works

int Attribute :: getY(){ 
    return map.get_YPosition(); 
}    // member function works