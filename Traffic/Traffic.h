#include "../Screen/Screen.h"
#include "../Lane/Lane.h"

#ifndef LANEAUTOMATIONSIM_TRAFFIC_H
#define LANEAUTOMATIONSIM_TRAFFIC_H

#define TRAFFIC '<'

//Traffic color
#define YELLOW "\x1B[33m"

class Traffic {

private:
    //Interval that traffic is generated
    int interval;
    //Lane object to get gap value
    Lane lane;

public:
    //Constructor
    Traffic();

    //Get and set interval value
    int getInterval();
    void setInterval(int);

    //Set lane object
    void setLane(Lane);

    //Generate oncoming traffic
    void setTraffic(char[][WIDTH], int, int);

};

#endif //LANEAUTOMATIONSIM_TRAFFIC_H
