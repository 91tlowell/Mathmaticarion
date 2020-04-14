#include "Player.h"
#include "Boss.h"
#include "Map.h"

#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H


class Attribute{
public:
    Attribute();
    std::string getListOfUpgrades();    // member function works
    void setAddUgrade(std::string); //  member function works set/add an upgrade to array.
    std::string getPlayerUpgradeList(); // member fucntion works returns upgrades palyer has obtained
    
    int healthUpgradeFunction (int); // member function works for upgrade to reduce health loss by a factor of 2.
    int staminaUpgradeFunction (int); // increase the time to be able to perform a task. 
    void accessTaskListsUpgradeFucntion (); // member function works std::string taskArr[number Of Tasks In Array]  (like print books function) access list of tasks for each boss
    int evadeUpgradeFunction (int); // taskValue[size of array] returns # xp for specific task and updates players xp.
    void jumpToMapLocation (int, int);  // displays "travel success" if player location change was successful.
    
    // added 
    int getX(); // member function works
    int getY(); // member function works
    
private:
    int const static SIZE_ = 6;
    int const static SIZE = 2;
    std::string listOfUpgrades[SIZE_] = {"Minimize Health Loss ", "Minimize Stamina Loss ", "Access Task List ", "Evade Upgrade ", "Access Map Upgrade ", "Jump To Map Location"};
    std::string upgrades[SIZE];    // if the character has a specific upgrade then that will aid in fighting the enemy.
    Player player;
    Boss boss;
    Map map;
};

#endif