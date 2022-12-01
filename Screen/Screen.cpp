#include <iostream>
#include "../Lane/Lane.h"
#include "Screen.h"
#include "../Vehicle/Vehicle.h"
#include "../TrafficLight/TrafficLight.h"

using namespace std;

void Screen::printSimScreen(char b[][WIDTH], int p, int ti, int u, int tu, int l) {
    int i, j, k, start, end;
    system("cls");
    string s = "";
    bool found;

    for (i = 0; i < WIDTH; i++)  {
        if (i == 0)
            s += " ";
        s += "=";
    }
    s += "\n";

    for (i = 0; i < LENGTH; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (j == 0) {
                s += " ";
                start = 0, end = 0, k = 0;
                found = false;
                while (!found) {
                    if (b[k][0] == LANE) {
                        start = k;
                        end = start + GAP;
                        found = true;
                    }
                    else
                        k++;
                }
                if (i < start || i > end)
                    s += '|';
                else {
                    if (isObject(b, i, j)) {
                        s += getColor(b, i, j);
                    }
                    else
                        s += b[i][j];
                }
            }
            else {
                if (isObject(b, i, j)) {
                    s += getColor(b, i, j);
                }
                else
                {
                    if (j == WIDTH - 1) {
                        if (i < p || i > p + GAP)
                            s += '|';
                        else
                            s += b[i][j];
                    }
                    else
                        s += b[i][j];
                }
            }
        }
        s += "\n";
    }

    for (i = 0; i < WIDTH; i++)  {
        if (i == 0)
            s += " ";
        s += "=";
    }

    cout << s;
    printf("\n Time: %ds   Units: %d   Vehicle Turns: %d   Traffic Lights: %d\n", ti, u, tu, l);
}

bool Screen::isObject(char b[][WIDTH], int i, int j) {
    bool o = false;
    if (b[i][j] == VEHICLE ||
        b[i][j] == STOP ||
        b[i][j] == GO)
        o = true;

    return o;
}

string Screen::getColor(char b[][WIDTH], int i, int j) {
    string s = "";
    if (b[i][j] == VEHICLE) {
        s += BLUE;
        s += b[i][j];
        s += RESET;
    }
    else if (b[i][j] == STOP) {
        s += RED;
        s += b[i][j];
        s += RESET;
    }
    else if (b[i][j] == GO) {
        s += GREEN;
        s += b[i][j];
        s += RESET;
    }

    return s;
}

void Screen::copyNextColumn(char b[][WIDTH], int c) {
    int i;

    for (i = 0; i < LENGTH; i++) {
        b[i][c] = b[i][c + 1];
    }
}

void Screen::animateLane(char b[][WIDTH]) {
    int i;
    for (i = 0; i < WIDTH - 1; i++) {
        copyNextColumn(b, i);
    }
}