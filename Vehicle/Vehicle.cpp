#include "Vehicle.h"
#include "../TrafficLight/TrafficLight.h"

void Vehicle::setInitialVehicle(char b[][WIDTH], int x, int y) {
    b[x][y] = VEHICLE;
}

bool Vehicle::trafficLightLogic(char b[][WIDTH], int x, int y) {
    bool r = false;
    if (b[x][y + 1] == STOP || b[x][y + 1] == GO) {
        lights++;
        if (b[x][y + 1] == STOP)
            r = true;
    }
    else if (b[x + 1][y + 1] == STOP || b[x + 1][y + 1] == GO) {
        lights++;
        if (b[x + 1][y + 1] == STOP)
            r = true;
    }
    else if (b[x - 1][y + 1] == STOP || b[x - 1][y + 1] == GO) {
        lights++;
        if (b[x - 1][y + 1] == STOP)
            r = true;
    }

    return r;
}

int Vehicle::automationLogic(char b[][WIDTH], int x, int y) {
    int m = 0;
    if (b[x][y + 1] == LANE) {
        turns++;
        if (b[x + 1][y] == LANE)
            m = -1;
        else if (b[x - 1][y] == LANE)
            m = 1;
    }

    return m;
}

void Vehicle::animateVehicle(char b[][WIDTH], int x, int y) {
    int i;
    for (i = 0; i < LENGTH; i++) {
        if (b[i][y - 1] == VEHICLE) {
            if (b[i + 1][y - 1] == GO || b[i - 1][y - 1] == GO)
                b[i][y - 1] = GO;
            else if (b[i + 1][y - 1] == STOP || b[i - 1][y - 1] == STOP)
                b[i][y - 1] = STOP;
            else
                b[i][y - 1] = ' ';
        }
    }

    units++;
    b[x][y] = VEHICLE;
}

int Vehicle::getTurns() {
    return turns;
}

int Vehicle::getLights() {
    return lights;
}

int Vehicle::getUnits() {
    return units;
}