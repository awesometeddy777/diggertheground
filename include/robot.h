#ifndef ROBOTH
#define ROBOTH

#include "main.h"
#include "pros/adi.hpp"
#include "pros/motors.h"
#include "api.h"
// #include "auton.h"
#include "robot.h"

using namespace pros;

extern pros::Controller controller;

// ----- Defines & Variables ----- //
#define LF_PORT 20
#define LM_PORT 19
#define LB_PORT 10
#define RF_PORT 11
#define RM_PORT 13
#define RB_PORT 1

#define INTAKE1 2
#define INTAKE2 9

#define IMU_PORT 6
#define RACE_DETECTOR_PORT 3

#define VERTICAL_ENCODER 4
#define LATERAL_ENCODER 5

extern bool lickerMechToggle;
extern bool blockBlockToggle;
extern bool lickerToggle;
extern bool descoreToggle;
extern bool raceMechToggle;
extern bool tankToggle;

extern double dRight;
extern double dLeft;
extern double rightDriveD;
extern double leftDriveD;

// ----- Motors ----- //
extern Motor left_motor_front;
extern Motor left_motor_middle;
extern Motor left_motor_back;
extern Motor right_motor_front;
extern Motor right_motor_middle;
extern Motor right_motor_back;

extern Motor intake1;
extern Motor intake2;

// ----- Pneumatics ----- //
extern ADIDigitalOut angleChanger;
extern ADIDigitalOut blockBlock;
extern ADIDigitalOut lickerMech;
extern ADIDigitalOut descore;
extern ADIDigitalOut raceMech;

// ----- Sensors ----- //
extern Imu imu;
extern Optical raceDetector;

extern Rotation verticalEncoder;
extern Rotation lateralEncoder;

#endif