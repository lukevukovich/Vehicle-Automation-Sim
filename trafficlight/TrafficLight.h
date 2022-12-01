#include "../Lane/Lane.h"

#ifndef LANEAUTOMATIONSIM_TRAFFICLIGHT_H
#define LANEAUTOMATIONSIM_TRAFFICLIGHT_H

//Interval traffic lights are randomly generated
#define INTERVAL 20

//Stop and go characters
#define STOP '['
#define GO ']'
//Red/green light colors
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"

class TrafficLight {

public:

    //Generate traffic light
    void setTrafficLight(char[][WIDTH], int, int);
    //Turn traffic light green at specific column
    void turnGreen(char[][WIDTH], int);

};

#endif //LANEAUTOMATIONSIM_TRAFFICLIGHT_H
