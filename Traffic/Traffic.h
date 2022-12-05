#include "../Screen/Screen.h"
#include "../Lane/Lane.h"

#ifndef LANEAUTOMATIONSIM_TRAFFIC_H
#define LANEAUTOMATIONSIM_TRAFFIC_H

#define TRAFFIC '<'

#define YELLOW "\x1B[33m"

class Traffic {

public:
    void setTraffic(char[][WIDTH], int, int);

};

#endif //LANEAUTOMATIONSIM_TRAFFIC_H
