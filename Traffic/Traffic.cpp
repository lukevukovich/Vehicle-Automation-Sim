#include "../Lane/Lane.h"
#include "Traffic.h"
#include "../TrafficLight/TrafficLight.h"

Traffic::Traffic() {
    interval = 5;
}

Traffic::Traffic(int i) {
    interval = i;
}

void Traffic::setInterval(int i) {
    interval = i;
}

int Traffic::getInterval() {
    return interval;
}

void Traffic::setLane(Lane l) {
    lane = l;
}

void Traffic::setTraffic(char b[][WIDTH], int u, int p) {
    int x;
    if (u % interval == 0) {
        x = rand() % (lane.getGap() - 4) + p + 3;
        if (b[x][WIDTH - 1] != STOP && b[x][WIDTH - 1] != GO) {
            if (b[x][WIDTH - 2] != TRAFFIC)
                b[x][WIDTH - 1] = TRAFFIC;
        }
    }
}
