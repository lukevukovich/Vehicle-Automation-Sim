#include <string>
#include "Lane.h"
#include "../Vehicle/Vehicle.h"
#include "../TrafficLight/TrafficLight.h"

Lane::Lane() {
    gap = 6;
}

Lane::Lane(int g) {
    gap = g;
}

int Lane::getGap() {
    return gap;
}

void Lane::setGap(int g) {
    gap = g;
}

void Lane::setInitialLane(char b[][WIDTH], int p) {
    int i;
    for (i = 0; i < WIDTH - 1; i++) {
        b[p][i] = LANE;
        b[p + gap + 1][i] = LANE;
    }
}

int Lane::getValidLanePiece(char b[][WIDTH], int p) {
    int piece;
    if (p == 0)
        piece = p + (rand() % 2);
    else if (p == LENGTH - gap - 2)
        piece = p + ((rand() % 2) - 1);
    else
        piece = p + ((rand() % 3) - 1);
    return piece;
}

void Lane::setLanePiece(char b[][WIDTH], int r, int x) {
    int i;
    for (i = 0; i < LENGTH; i++) {
        b[i][x] = ' ';
    }

    b[r][x] = LANE;
    b[r + gap + 1][x] = LANE;
}
