#include "../Screen/Screen.h"
#include "../Lane/Lane.h"

#ifndef LANEAUTOMATIONSIM_TRAFFIC_H
#define LANEAUTOMATIONSIM_TRAFFIC_H

#define TRAFFIC '<'

//Traffic color
#define YELLOW "\x1B[33m"

class Traffic {

public:
    //Generate oncoming traffic
    void setTraffic(char[][WIDTH], int, int);

};

#endif //LANEAUTOMATIONSIM_TRAFFIC_H
