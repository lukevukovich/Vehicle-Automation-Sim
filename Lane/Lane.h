#include <string>

#ifndef LANEAUTOMATIONSIM_LANE_H
#define LANEAUTOMATIONSIM_LANE_H

//Length & width of sim board
#define LENGTH 25
#define WIDTH (LENGTH*3)
//Lane width (GAP - 1)
#define GAP 6
//Lane edge character
#define LANE 'W'
//Reset char color
#define RESET "\x1B[0m"

using namespace std;

class Lane {

public:
    //Set initial straight lane at start of sim
    void setInitialLane(char[][WIDTH], int);
    //Generate valid lane section
    //Returns starting y position (left edge) of lane
    int getValidLanePiece(char[][WIDTH], int);
    //Set new lane section
    void setLanePiece(char[][WIDTH], int, int);

};

#endif //LANEAUTOMATIONSIM_LANE_H
