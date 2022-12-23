#include <iostream>
#include "Vehicle.h"
#include "../TrafficLight/TrafficLight.h"
#include "../Traffic/Traffic.h"

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

int Vehicle::turnLogic(char b[][WIDTH], int x, int y) {
    int m = 0, t;
    if (b[x][y + 1] == LANE) {
        turns++;
        if (b[x + 1][y] == LANE)
            m = -1;
        else if (b[x - 1][y] == LANE)
            m = 1;
    }
    else if (b[x][y + 1] == TRAFFIC) {
        int lGap = 0, rGap = 0, i;

        i = x;
        while (b[i][y + 1] != LANE) {
            lGap++;
            i--;
        }

        i = x;
        while (b[i][y + 1] != LANE) {
            rGap++;
            i++;
        }

        if (lGap > rGap)
            m = -1;
        else if (rGap > lGap)
            m = 1;
        else {
            m = 1;

            t = rand() % 2;
            if (t == 0)
                m = -m;
        }

        turns++;
        traffic++;
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

int Vehicle::getTraffic() {
    return traffic;
}

int Vehicle::getLights() {
    return lights;
}

int Vehicle::getUnits() {
    return units;
}