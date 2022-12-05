#include "../Lane/Lane.h"
#include "Traffic.h"
#include "../TrafficLight/TrafficLight.h"

void Traffic::setTraffic(char b[][WIDTH], int u, int p) {
    int x;
    if (u % 5 == 0) {
        x = rand() % (GAP - 1) + p + 1;
        if (b[x][WIDTH - 1] != STOP && b[x][WIDTH - 1] != GO) {
            if (b[x][WIDTH - 2] != TRAFFIC)
                b[x][WIDTH - 1] = TRAFFIC;
        }
    }
}
