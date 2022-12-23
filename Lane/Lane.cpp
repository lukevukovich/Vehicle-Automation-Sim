#include <string>
#include "Lane.h"
#include "../Vehicle/Vehicle.h"
#include "../TrafficLight/TrafficLight.h"

void Lane::setInitialLane(char b[][WIDTH], int p) {
    int i;
    for (i = 0; i < WIDTH - 1; i++) {
        b[p][i] = LANE;
        b[p + GAP + 1][i] = LANE;
    }
}

int Lane::getValidLanePiece(char b[][WIDTH], int p) {
    int piece;
    if (p == 0)
        piece = p + (rand() % 2);
    else if (p == LENGTH - GAP - 2)
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
    b[r + GAP + 1][x] = LANE;
}
