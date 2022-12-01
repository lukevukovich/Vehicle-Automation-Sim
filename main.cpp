#include <windows.h>
#include <ctime>
#include <conio.h>
#include "Lane/Lane.h"
#include "Vehicle/Vehicle.h"
#include "TrafficLight/TrafficLight.h"
#include "Screen/Screen.h"

using namespace std;

/*
 * All vehicle automation/detection logic is standalone from simulation generation.
 * Vehicle logic detects lane edge, traffic lights, and traffic.
 */

int main() {
    //Create sim board
    char board[LENGTH][WIDTH];

    int i, j, laneStart, vehicleX, vehicleY, vehicleMove, turns, units, lights, generate;

    time_t start, end;
    int diff, elapsed = 0;

    bool isRedLight;

    srand(time(nullptr));

    //Clear board/lane
    for (i = 0; i < LENGTH; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = ' ';
        }
    }

    //Create objects
    Screen screen = Screen();
    Lane lane = Lane();
    Vehicle vehicle = Vehicle();
    TrafficLight trafficLight = TrafficLight();

    //Set initial lane position
    //laneStart : starting y position of lane. Lane has width of GAP - 1
    laneStart = rand() % (LENGTH - GAP);
    lane.setLanePiece(board, laneStart, WIDTH - 1);
    lane.setInitialLane(board, laneStart);

    //Set vehicle position values
    vehicleX = laneStart + GAP - 1;
    vehicleY = WIDTH/2;
    vehicle.setInitialVehicle(board, vehicleX, vehicleY);

    turns = 0, units = 0, lights = 0;

    //Start timer
    time(&start);

    //Loop until keyboard hit is detected
    while(!kbhit()) {

        //Print sim screen
        screen.printSimScreen(board, laneStart, elapsed, units, turns, lights);

        //Check for red light
        isRedLight = vehicle.trafficLightLogic(board, vehicleX, vehicleY);

        //If red light, stop for 2 seconds, turn light green
        if (isRedLight) {
            i = 0;
            while (i < 5 && !kbhit()) {
                if (i == 4) {
                    trafficLight.turnGreen(board, vehicleY + 1);
                }
                //Update time while vehicle is stopped
                time(&end);
                diff = (int) difftime(end, start);
                elapsed = diff;

                //Update screen while vehicle is stopped
                screen.printSimScreen(board, laneStart, elapsed, units, turns, lights);
                Sleep(500);

                i++;
            }
        }

        //Set number of lights passed
        lights = vehicle.getLights();

        //Get vehicle's vertical move based on lane position
        vehicleMove = vehicle.automationLogic(board, vehicleX, vehicleY);
        vehicleX += vehicleMove;
        //Set number of vehicle turns
        turns = vehicle.getTurns();

        //Move all columns 1 to the left to give on animation effect
        screen.animateLane(board);
        //Get new chunk of lane to generate
        laneStart = lane.getValidLanePiece(board, laneStart);
        lane.setLanePiece(board, laneStart, WIDTH - 1);
        //Set number of units traveled
        units = vehicle.getUnits();

        generate = rand() % 3;
        //Generate traffic light
        if (units > INTERVAL && generate == 0)
            trafficLight.setTrafficLight(board, units, laneStart);

        //Move vehicle based on automation logic
        vehicle.animateVehicle(board, vehicleX, vehicleY);

        //Updated time
        time(&end);
        diff = (int) difftime(end, start);
        elapsed = diff;

    }

    return 0;
}
