#include "../Lane/Lane.h"

#ifndef LANEAUTOMATIONSIM_SCREEN_H
#define LANEAUTOMATIONSIM_SCREEN_H

class Screen {

private:
    Lane lane;

    //Checks if value is an object (vehicle or traffic light)
    bool isObject(char[][WIDTH], int, int);
    //Set color of certain objects
    //Returns colored string (if needed)
    string getColor(char[][WIDTH], int, int);
    //Copy value of column to right
    void copyNextColumn(char[][WIDTH], int);

public:

    void setLane(Lane);

    //Print one screen frame : border, lane, vehicle, traffic lights, sim data
    void printSimScreen(char[][WIDTH], int, int, int, int, int, int);
    //Copy all column values to animate frame
    void animateLane(char[][WIDTH]);

};

#endif //LANEAUTOMATIONSIM_SCREEN_H
