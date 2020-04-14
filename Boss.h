#ifndef BOSS_H
#define BOSS_H

class Boss{
public:
    Boss();
    int getBossHealth();    // member function works
    int getBossStamina();   // member function works
    void setBossHealth(int);    // member funciton works
    void printTaskList();   // member function works
    void loadTaskToArray(std::string);    // member function works depending on the players XP value, a specific task list will be loaded.
    void loadTaskAnswToArray(std::string);    // member function works depending on the players XP value, a specific task list will be loaded.
    std::string presentTaskFunction(int);  // member function works choose random index to display task while fighting boss.
    std::string responseFunction(std::string); // if the player gets task correct or incorrect a response is displayed at random.
    int getIndexTaskList(); // member function works
    void setIndexTaskList(int); // member function works
    // void checkAnswerFunction();
    int randomNumGenerator();   // member funciton works
    std::string presentTaskFunctionAnswer(int idx); // member function works
    
    
private:
    int const static size = 40;
    std::string bossResponseCorrect[6] = {"Ah, you're a worthy opponent!", "I didn't expect such an intellect.", "Lets see if the next one is so easy for you.", "I thought I had you on that one!", "How can this be!?", "Your brain must be firing on all cylinders."}; 
    std::string bossResponeIncorrect[5] = {"Ha! not so smart are ya!?", "Gotcha on that one!", "Looks like you have to study up more.", "I guess my questions are just too tough.", "Give up yet?"};
    std::string bossArray[size];
    std::string bossAnswArray[size];
    int index;
    int bossHealth;
    int bossStamina;
    
};

#endif