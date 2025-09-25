extern bool lickerMechToggle;
extern bool blockBlockToggle;
extern bool lickerToggle;
extern bool descoreToggle;
extern bool raceMechToggle;
extern bool tankToggle;

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
