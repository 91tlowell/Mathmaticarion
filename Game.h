#include "Player.h"
#include "Map.h"
#include "Attribute.h"
#include "Boss.h"

#ifndef GAME_H
#define GAME_H

class Game{
public:
    Game ();
    void postitionAdvanceFucntion(int); // will only advance palyer if they have completed task correctly
    void menuLoop();
    void fight();
    void checkAnswerFunction(); // member function works
    void storeFunction();   // member function works
    void saveGameFunction(std::string); // member function works
    void loadGameLevelFunction(std::string);   // member function works
    // the majority of the interaction with the game will be here in the larger class
    // while the smaller classes will have just "get" and "set" to facilitate the member fuctions of the larger class. 
    
private:
    Map map;
    Player player;
    Boss boss;
    Attribute attribute;
    
};

#endif

/* game(level) dependent functions for the game class
- read in saved information
    - map
    - health
    - stamina
    - experience points
    - upgrades

- fight function
    - 1st check what position on the map player is on
    - if on the boss poistion 
        - check if player has enough experience points
            - cout << promt << endl;
                - enemy "speech"
                - expectations(what the tasks are)
                    - display a menu choice 
                        - to fight
                        - or 
                        - exit to return later

- store function
    -display greeting and menu options
        - "what would you like to do?"
        if (buy health)
            - reduce currency by x amount of integers
            - increase heatlth
            - cout << witty statement about being rejuvinated
        if (buy stamina)
            - reduce currency by x amount of integers
            - increase stamin
            - cout << witty staement about being refreshed
        else
            - cout << statement from shop clerk

- map function // for landing on a spot on the map where player can see map without having the upgrade(that allow to see the map anytime)        
    - if (player position is "map")
        - call map print function

- save game function
    - write all player specific information to a file
        if (player position is not equal to (call function currenct position))  // autosave function
            - write to file, player's information to be updated
            - cout << save successful

- load game function
    if (user name is equal to user name)
        - read from file player information
            - update
                health
                stamina
                experience points
                upgrades
                    - if succesful cout << load succesful
                        - update currenct position to the start posisiton of the map that corresponds to number experience points

- travel function
    - move character by keybard press
        if keyboard input is equal to 'n'
            - move player one space north
                - check if position is mountain, water, H, U, B
        if keyboard input is equal to 's'
            - move player one space south
                - check if position is mountain, water, H, U, B
        if keyboard input is equal to 'w'
            - move player one space west
                - check if position is mountain, water, H, U, B
        if keyboard input is equal to 'e'
            - move player one space east
                - check if position is mountain, water, H, U, B
*/
