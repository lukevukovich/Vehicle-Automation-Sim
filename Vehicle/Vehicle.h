#include "../Lane/Lane.h"

#ifndef LANEAUTOMATIONSIM_VEHICLE_H
#define LANEAUTOMATIONSIM_VEHICLE_H

//Vehicle character
#define VEHICLE '>'
//Vehicle color
#define BLUE "\x1B[36m"

class Vehicle {
private:
    //Keep track of sim data. Vehicle functions update these values
    int units = 1;
    int turns = 0;
    int lights = 0;
    int traffic = 0;

public:

    //Set vehicle position to center of screen and inside of lane
    void setInitialVehicle(char[][WIDTH], int, int);
    //Vehicle's reaction to traffic light
    //Returns true if red light
    bool trafficLightLogic(char[][WIDTH], int, int);
    //Get vehicle's vertical move (if needed) based on lane edges
    //Returns vertical move (-1, 0, 1)
    int turnLogic(char[][WIDTH], int, int);
    //Set vehicle's move
    void animateVehicle(char[][WIDTH], int, int);

    //Getter functions
    int getUnits();
    int getTurns();
    int getTraffic();
    int getLights();

};

#endif //LANEAUTOMATIONSIM_VEHICLE_H
