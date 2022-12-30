//
// Created by Luke on 12/29/2022.
//

#include "InputUI.h"
#include <iostream>
#include <climits>

using namespace std;

//Create string header
void InputUI::header(string s) {
    string dashes, header;
    int len = s.length(), i;

    //Horizontal line of dashes
    dashes = " ";
    for (i = 0; i < (len + 4); i++)
        dashes += "-";

    //Build header
    header += "" + dashes;
    header += "\n | " + s + " |\n";
    header += dashes;

    cout << header;
}

//Create individual UI option
void InputUI::option(int n, string s) {
    string opt;

    //Build option with number and string
    opt = "\n ";
    opt += "(" + to_string(n) + ") " + s;

    cout << opt;
}

//Receive input for speed value
int InputUI::speedInput() {
    int in;
    speed_enum speed;

    //Create UI layout
    header("SPEED");
    option(1, "Slow");
    option(2, "Normal");
    option(3, "Fast");

    //Ask user for input
    cout << "\n\n Select: ";
    cin >> in;

    while (!cin.good() || (in != 1 && in != 2 && in != 3)) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cout << " Select: ";
        cin >> in;
    }

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    //Set speed to specific enum
    if (in == 1)
        speed = SLOW;
    else if (in == 2)
        speed = NORMAL;
    else
        speed = FAST;

    system("cls");

    //Return specific enum value
    return speed;
}

//Receive input for lane width value
int InputUI::laneInput() {
    int in;
    lane_enum lane;

    //Create UI layout
    header("LANE");
    option(1, "Small");
    option(2, "Medium");
    option(3, "Large");

    //Ask for user input
    cout << "\n\n Select: ";
    cin >> in;

    while (!cin.good() || (in != 1 && in != 2 && in != 3)) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cout << " Select: ";
        cin >> in;
    }

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    //Set lane width to specific enum
    if (in == 1)
        lane = SMALL;
    else if (in == 2)
        lane = MEDIUM;
    else
        lane = LARGE;

    system("cls");

    //Return specific enum value
    return lane;
}

//Receive input for traffic light choice
int InputUI::lightInput() {
    int in;
    int light;

    //Create UI layout
    header("TRAFFIC LIGHTS");
    option(1, "Yes");
    option(2, "No");

    //Ask user for input
    cout << "\n\n Select: ";
    cin >> in;

    while (!cin.good() || (in != 1 && in != 2)) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cout << " Select: ";
        cin >> in;
    }

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    //Set light choice to specific enum
    if (in == 1)
        light = YES;
    else
        light = NO;

    system("cls");

    //Return specific enum value
    return light;
}

//Receive input for traffic density value
int InputUI::trafficInput() {
    int in;
    traffic_enum traffic;

    //Create UI layout
    header("TRAFFIC");
    option(1, "None");
    option(2, "Light");
    option(3, "Heavy");

    //Ask user for input
    cout << "\n\n Select: ";
    cin >> in;

    while (!cin.good() || (in != 1 && in != 2 && in != 3)) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cout << " Select: ";
        cin >> in;
    }

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    //Set traffic density to specific enum
    if (in == 1)
        traffic = NONE;
    else if (in == 2)
        traffic = LIGHT;
    else
        traffic = HEAVY;

    system("cls");

    //Return specific enum value
    return traffic;
}

//Get int value of YES (light_enum)
int InputUI::getYESValue() {
    return YES;
}