#include "../Screen/Screen.h"
#include "../Lane/Lane.h"

#ifndef LANEAUTOMATIONSIM_TRAFFIC_H
#define LANEAUTOMATIONSIM_TRAFFIC_H

#define TRAFFIC '<'

//Traffic color
#define YELLOW "\x1B[33m"

class Traffic {

private:
    int interval;
    Lane lane;

public:
    Traffic();
    Traffic(int);

    int getInterval();
    void setInterval(int);

    void setLane(Lane);

    //Generate oncoming traffic
    void setTraffic(char[][WIDTH], int, int);

};

#endif //LANEAUTOMATIONSIM_TRAFFIC_H
