#include <windows.h>
#include <ctime>
#include <conio.h>
#include "Lane/Lane.h"
#include "Vehicle/Vehicle.h"
#include "TrafficLight/TrafficLight.h"
#include "Screen/Screen.h"
#include "Traffic/Traffic.h"
#include "InputUI/InputUI.h"

using namespace std;

/*
 * All vehicle automation/detection logic is standalone from simulation generation.
 * Vehicle logic detects lane edge, traffic lights, and traffic.
 */

int main() {
    //Create sim board
    char board[LENGTH][WIDTH];

    int i, j;
    int gap, laneStart, vehicleX, vehicleY, vehicleMove;
    int units, turns, traffic, lights;
    int speedIn, lightIn, trafficIn, generate;

    time_t start, end;
    int diff, elapsed;

    bool isRedLight;
    bool exit = false;

    srand(time(nullptr));

    //Create objects
    Screen screen;
    Lane lane;
    Vehicle vehicle;
    TrafficLight trafficLight;
    Traffic oncomingTraffic;
    InputUI input;

    //Loop until user exits
    while (!exit) {

        //Reset objects
        screen = Screen();
        lane = Lane();
        vehicle = Vehicle();
        trafficLight = TrafficLight();
        oncomingTraffic = Traffic();
        input = InputUI();

        //Clear board/lane
        for (i = 0; i < LENGTH; i++) {
            for (j = 0; j < WIDTH; j++) {
                board[i][j] = ' ';
            }
        }

        //Get speed input from user
        speedIn = input.speedInput();

        //Get lane width input from user
        gap = input.laneInput();
        //Set lane gap/width
        lane.setGap(gap);
        //Set lane object
        //Used to obtain gap value within other objects
        screen.setLane(lane);
        trafficLight.setLane(lane);
        oncomingTraffic.setLane(lane);

        //Get traffic light input from user
        lightIn = input.lightInput();

        //Get traffic input from user
        trafficIn = input.trafficInput();
        oncomingTraffic.setInterval(trafficIn);

        //Set initial lane position
        //laneStart : starting y position of lane
        laneStart = rand() % (LENGTH - lane.getGap() - 1);
        lane.setLanePiece(board, laneStart, WIDTH - 1);
        lane.setInitialLane(board, laneStart);

        //Set vehicle position values
        vehicleX = laneStart + lane.getGap() - 1;
        vehicleY = WIDTH / 2;
        vehicle.setInitialVehicle(board, vehicleX, vehicleY);

        turns = 0, units = 0, lights = 0, traffic = 0;
        elapsed = 0;

        //Start timer
        time(&start);

        //Loop until keyboard hit is detected
        while (!_kbhit()) {

            //Print sim screen
            screen.printSimScreen(board, laneStart, elapsed, units, turns, traffic, lights);

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
                    screen.printSimScreen(board, laneStart, elapsed, units, turns, traffic, lights);
                    Sleep(500);

                    i++;
                }
            }

            //Set number of lights passed
            lights = vehicle.getLights();

            //Get vehicle's vertical move based on lane position
            vehicleMove = vehicle.turnLogic(board, vehicleX, vehicleY);
            vehicleX += vehicleMove;
            //Set number of vehicle turns and traffic passed
            turns = vehicle.getTurns();
            traffic = vehicle.getTraffic();

            //Move all columns 1 to the left to give on animation effect
            screen.animateLane(board);
            //Get new chunk of lane to generate
            laneStart = lane.getValidLanePiece(board, laneStart);
            lane.setLanePiece(board, laneStart, WIDTH - 1);
            //Set number of units traveled
            units = vehicle.getUnits();

            //Generate oncoming traffic
            if (oncomingTraffic.getInterval() != 0)
                oncomingTraffic.setTraffic(board, units, laneStart);

            generate = rand() % 3;
            //Generate traffic light
            if (units > INTERVAL && generate == 0 && lightIn == input.getYESValue())
                trafficLight.setTrafficLight(board, units, laneStart);

            //Move vehicle based on automation logic
            vehicle.animateVehicle(board, vehicleX, vehicleY);

            //Updated time
            time(&end);
            diff = (int) difftime(end, start);
            elapsed = diff;

            //Used to control sim speed
            Sleep(speedIn);

        }

        //If r is pressed, restart sim
        if (_getch() != 'r')
            exit = true;
        //If any other key is pressed, exit sim
        else
            system("cls");

    }

    return 0;
}
