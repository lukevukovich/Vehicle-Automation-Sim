cmake_minimum_required(VERSION 3.23)
project(LaneAutomationSim)

set(CMAKE_CXX_STANDARD 17)

add_executable(LaneAutomationSim main.cpp Lane/Lane.cpp Lane/Lane.h Vehicle/Vehicle.cpp Vehicle/Vehicle.h TrafficLight/TrafficLight.cpp TrafficLight/TrafficLight.h Screen/Screen.cpp Screen/Screen.h Traffic/Traffic.cpp Traffic/Traffic.h)
