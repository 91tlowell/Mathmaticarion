#ifndef MAP_H
#define MAP_H


class Map{
public:
    Map();
    void setPositionX (int);    // member function works
    void setPositionY (int);    // member function works
    int get_XPosition();    // member function works
    int get_YPosition();    // member function works
    void printMap(std::string); // member function works; populate map from respected level player is on.
    void loadMapToArray(std::string);   // member function works
    std::string getMapLocation();   // member function works
    std::string checkPlayerPostition(); // member function works
    void travelFunction(std::string);   // member function works (accout for edge cases)
    void loadTaskToTravelArray(std::string);   // member fucntion works
    void loadTaskToTravelArrayAnswers(std::string);   // member fucntion works
    std::string travelTaskGeneratorFunction(int);    // member function works
    int randomNumGeneratorForTravelTask();
    std::string travelFunctionAnswerCheck(int);

    
private:
    int position_X;
    int position_Y;
    int const static rowSize = 15;
    int const static columnSize = 15;
    std::string mapArr[rowSize][columnSize];
    int const static taskToTravelSIZE = 270;
    std::string taskToTravelArray[taskToTravelSIZE];
    std::string taskToTravelArrayAnswers[taskToTravelSIZE];
};

#endif