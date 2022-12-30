#include <iostream>

#ifndef LANEAUTOMATIONSIM_LANE_H
#define LANEAUTOMATIONSIM_LANE_H

//Length & width of sim board
#define LENGTH 25
#define WIDTH (LENGTH*3)
//Lane edge character
#define LANE 'W'
//Reset char color
#define RESET "\x1B[0m"

using namespace std;

class Lane {

private:
    //Lane width/gap attribute
    int gap;

public:
    //Constructors
    Lane();
    Lane(int);

    //Get and set gap value
    int getGap();
    void setGap(int);

    //Set initial straight lane at start of sim
    void setInitialLane(char[][WIDTH], int);
    //Generate valid lane section
    //Returns starting y position (left edge) of lane
    int getValidLanePiece(char[][WIDTH], int);
    //Set new lane section
    void setLanePiece(char[][WIDTH], int, int);

};

#endif //LANEAUTOMATIONSIM_LANE_H
