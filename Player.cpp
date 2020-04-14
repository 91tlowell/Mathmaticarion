#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

Player :: Player(){
    health = 100;
    stamina = 50;
    experiencePoints = 0;
    currency = 100;
    playerName = "";
}

Player :: Player(string playerName_){
    playerName = playerName_;
}

//_____Getters______
int Player :: getHealth(){
    return health;
}

int Player :: getStamina(){
    return stamina;
}

int Player :: getExperiencePoints(){
    return experiencePoints;
}

int Player :: getCurrency(){
    return currency;
}

string Player :: getPlayerName(){
    return playerName;
}

//_____Setters______
void Player :: setHealth(int health_){
    health = health_;
}

void Player :: setStamina(int stamina_){
    stamina = stamina_;
}

void Player :: setExperiencePoints(int experiencePoints_){
    experiencePoints = experiencePoints_;
}

void Player :: setCurrency(int currency_){
    currency = currency_;
}

void Player :: setPlayerName(string playerName_){
    playerName = playerName_;
}