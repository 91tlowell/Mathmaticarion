#ifndef PLAYER_H
#define PLAYER_H


class Player{ // different arrays for different enemies that correspond to specific attributes
public:
    Player();   //default consstructor
    Player (std::string);
    
//_____Getters________
    int getHealth();
    int getStamina();
    int getExperiencePoints();
    int getCurrency();
    std::string getPlayerName();
    
//____Setters_________
    void setHealth(int);
    void setStamina(int);
    void setExperiencePoints(int);
    void setCurrency(int);
    void setPlayerName(std::string);

private:
    int health;
    int stamina;
    int experiencePoints;
    int currency;
    std::string playerName;
};

#endif