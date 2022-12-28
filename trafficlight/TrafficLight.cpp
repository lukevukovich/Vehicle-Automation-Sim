#include <cstdlib>
#include "TrafficLight.h"
#include "../Lane/Lane.h"

void TrafficLight::setLane(Lane l) {
    lane = l;
}

void TrafficLight::setTrafficLight(char b[][WIDTH], int u, int p) {
    int i, x;
    
    if (u % INTERVAL == 0) {
        x = rand() % 2;
        for (i = p + 1; i < p + lane.getGap() + 1; i++) {
            if (x == 0)
                b[i][WIDTH - 1] = STOP;
            else
                b[i][WIDTH - 1] = GO;
        }
    }
}

void TrafficLight::turnGreen(char b[][WIDTH], int y) {
    int start, end, i;
    bool found = false;

    i = 0;
    while (!found) {
        if (b[i][y] == LANE) {
            start = i;
            end = start + lane.getGap() + 1;
            found = true;
        }
        else
            i++;
    }

    for (i = start + 1; i < end; i++) {
        b[i][y] = GO;
    }
}