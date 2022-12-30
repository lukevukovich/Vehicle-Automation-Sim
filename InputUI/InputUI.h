#include <iostream>

#ifndef LANEAUTOMATIONSIM_INPUTUI_H
#define LANEAUTOMATIONSIM_INPUTUI_H

//Enums used for user customization
enum speed_enum {SLOW = 125, NORMAL = 25, FAST = 0};
enum lane_enum {SMALL = 6,  MEDIUM = 8, LARGE = 10};
enum light_enum {YES = 1, NO = 2};
enum traffic_enum {NONE = 0, LIGHT = 8, HEAVY = 4};

using namespace std;

class InputUI {

private:
    //Create UI header
    void header(string);
    //Create UI option
    void option(int, string);

public:
    //Receive user input for specific environment values
    int speedInput();
    int laneInput();
    int lightInput();
    int trafficInput();

    //Return value of YES enum
    int getYESValue();

};

#endif //LANEAUTOMATIONSIM_INPUTUI_H
